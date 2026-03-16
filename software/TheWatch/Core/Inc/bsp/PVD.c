/*
 * PVD.c
 *
 *  Created on: 13 lut 2026
 *      Author: kwojcik
 */
#include <stdint.h>
#include <stdio.h>
#include "main.h"
#include "bsp/PVD.h"

void PVD_Enable(void)
{
    PWR->CR |= PWR_CR_PVDE;
    PWR->CR |= PWR_CR_PLS_LEV3;   // próg ~2.5V (zależny od MCU)

    EXTI->IMR  |= EXTI_IMR_MR16;
    EXTI->RTSR |= EXTI_RTSR_TR16;

    NVIC_EnableIRQ(PVD_IRQn);
}

//void PVD_IRQHandler(void)
//{
//    if (EXTI->PR & EXTI_PR_PR16)
//    {
//        EXTI->PR = EXTI_PR_PR16;
//
//        /* OSTATNIA SZANSA */
//        BackupRtc_Save();
//        // zapisz licznik, stan, RTC itp.
//    }
//}

uint8_t WasPowerLost(void)
{
    uint8_t lost = 0;

    PWR->CR |= PWR_CR_DBP;

    if (RTC->BKP0R != BKP_RTC)
        lost = 1;

    RTC->BKP0R = BKP_RTC;    // odtwórz znacznik

    PWR->CR &= ~PWR_CR_DBP;

    return lost;
}

void BackupRtc_Save(void)
{
    PWR->CR |= PWR_CR_DBP;     // enable backup access
    RTC->BKP0R = BKP_RTC;
    PWR->CR &= ~PWR_CR_DBP;
}

