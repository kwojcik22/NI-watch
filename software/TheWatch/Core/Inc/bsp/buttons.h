/*
 * statuses.h
 *
 *  Created on: Feb 12, 2026
 *      Author: kwojcik
 */

#ifndef INC_STATUS_MNGR_STATUSES_H_
#define INC_STATUS_MNGR_STATUSES_H_

#include <stdint.h>
#include <stdio.h>
#include "stm32f0xx.h"

#define SHORT_PRESS_MS  100
#define LONG_PRESS_MS   3000

typedef union
{
    struct
    {
        uint8_t pressed     : 1;
        uint8_t released    : 1;
        uint8_t short_press : 1;
        uint8_t long_press  : 1;
        uint8_t repeat      : 1;
        uint8_t reserved    : 3;
    };
    uint8_t raw;
} button_flags_t;

typedef struct
{
    button_flags_t flags;      // events flags

    uint32_t press_time_tick;  // start press timestamp
    uint32_t last_change_tick; // stop press timestamp
    GPIO_PinState current_state;
    GPIO_PinState previous_state;
    GPIO_TypeDef *GPIOx;				//button register group
    uint16_t GPIO_PINx;			//button register pin
} button_t;


void init_Btn(button_t *btn, GPIO_TypeDef *gpiox, uint32_t gpio_pinx);
void Button_ClearFlags(button_t *btn);
uint8_t Button_Pressed(button_t *btn);
void Button_Read(button_t *btn);



#endif /* INC_STATUS_MNGR_STATUSES_H_ */
