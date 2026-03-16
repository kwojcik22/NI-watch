/*
 * Time.h
 *
 *  Created on: 13 lut 2026
 *      Author: kwojcik
 */

#ifndef INC_BSP_RTC_TIME_H_
#define INC_BSP_RTC_TIME_H_

#include <stdint.h>
#include <stdio.h>
#include "stm32f0xx_hal.h"
#include <logger/logger.h>
#include "stm32f0xx_hal_conf.h"

#define RTC_WRITE_PROTECT_DISABLE()  \
    do { RTC->WPR = 0xCA; RTC->WPR = 0x53; } while (0)

#define RTC_WRITE_PROTECT_ENABLE()   \
    do { RTC->WPR = 0xFF; } while (0)


void RTC_ReadTimeBCD(uint8_t *hh, uint8_t *mm);
void RTC_SetTimeBCD(uint8_t hh, uint8_t mm);
void RTC_Stop(void);
void RTC_SetAlarmBCD(RTC_HandleTypeDef *hrtc, uint8_t hh, uint8_t mm);
void RTC_DisableAlarm(void);
void RTC_EnableAlarmIRQ(void);



#endif /* INC_BSP_RTC_TIME_H_ */
