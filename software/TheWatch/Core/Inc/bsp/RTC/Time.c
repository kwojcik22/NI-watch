/*
 * Time.c
 *
 *  Created on: 13 lut 2026
 *      Author: kwojcik
 */
#include <bsp/RTC/Time.h>
#include "rtc.h"

void RTC_ReadTimeBCD(uint8_t *hh, uint8_t *mm)
{
    uint32_t tr = RTC->TR;

    *hh = (tr >> 16);
    *mm = (tr >> 8);
}

void RTC_SetTimeBCD(uint8_t hh, uint8_t mm)
{
    RTC_WRITE_PROTECT_DISABLE();

    RTC->ISR |= RTC_ISR_INIT;
    while (!(RTC->ISR & RTC_ISR_INITF));

    RTC->TR =
        ((uint32_t)hh << 16) |
        ((uint32_t)mm << 8);

    RTC->ISR &= ~RTC_ISR_INIT;

    RTC_WRITE_PROTECT_ENABLE();
}

void RTC_Stop(void)
{
    RTC_WRITE_PROTECT_DISABLE();
    RTC->CR &= ~RTC_CR_FMT;   // nie resetuje czasu
    RTC_WRITE_PROTECT_ENABLE();
}

/**
 * @brief setting new alarm value
 * @param  bcd formatted function input
 */
void RTC_SetAlarmBCD(RTC_HandleTypeDef *hrtc, uint8_t hh, uint8_t mm)
{
	RTC_AlarmTypeDef setAlarm={0};

	setAlarm.AlarmTime.Hours = hh;
	setAlarm.AlarmTime.Minutes = mm;
	setAlarm.AlarmTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	setAlarm.AlarmTime.StoreOperation = RTC_STOREOPERATION_SET;
	setAlarm.AlarmMask = RTC_ALARMMASK_DATEWEEKDAY|RTC_ALARMMASK_SECONDS;
	setAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_ALL;
	setAlarm.AlarmDateWeekDaySel = RTC_ALARMDATEWEEKDAYSEL_DATE;
	setAlarm.AlarmDateWeekDay = 0x1;
	setAlarm.Alarm = RTC_ALARM_A;

	HAL_RTC_SetAlarm_IT(hrtc, &setAlarm, RTC_FORMAT_BCD);
}

/**
 * @brief disabling RTC alarm functionality
 */
void RTC_DisableAlarm(void)
{
    RTC_WRITE_PROTECT_DISABLE();
    RTC->CR &= ~RTC_CR_ALRAE;
    RTC_WRITE_PROTECT_ENABLE();
}

/**
 * @brief Enabling RTC alarm functionality
 */
void RTC_EnableAlarmIRQ(void)
{
    RTC_WRITE_PROTECT_DISABLE();
    RTC->CR |= RTC_CR_ALRAE;
    RTC_WRITE_PROTECT_ENABLE();

    NVIC_EnableIRQ(RTC_IRQn);
}

