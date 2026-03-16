/*
 * Buttons.c
 *
 *  Created on: Feb 12, 2026
 *      Author: kwojcik
 */


#include <bsp/buttons.h>
#include <stdint.h>
#include <stdio.h>
#include "logger/logger.h"
#include "stm32f0xx_hal.h"

void init_Btn(button_t *btn, GPIO_TypeDef *gpiox, uint32_t gpio_pinx)
{
	btn->flags.raw = 0b00000000;
	btn->last_change_tick = 0;
	btn->previous_state = GPIO_PIN_RESET;
	btn->press_time_tick = 0;

	btn->GPIOx = gpiox;
	btn->GPIO_PINx = gpio_pinx;
}

void Button_ClearFlags(button_t *btn)
{
    btn->flags.raw = 0b00000000;
}

void Button_Read(button_t *btn)
{
    /* active LOW */
	if((btn->GPIOx->IDR & btn->GPIO_PINx) == 0U){
		btn->flags.pressed =  1U;
	}else{
		btn->flags.pressed =  0U;
	}
}

uint8_t Button_Pressed(button_t *btn)
{
		uint32_t now = HAL_GetTick();
		Button_Read(btn);
	    uint8_t state = btn->flags.pressed;
	    uint8_t last  = btn->previous_state;

	    if (state != last)
	    {
	        btn->previous_state = state;
	        btn->last_change_tick = now;

	        if (state) /* PRESSED */
	        {
	            btn->press_time_tick = now;
	        }
	        else /* RELEASED */
	        {
	            uint32_t press_time = now - btn->press_time_tick;

	            if (press_time >= LONG_PRESS_MS)
	            {
	                btn->flags.long_press = 1U;
	                log_printf(LOG_DEBUG, "btn: long_press");
	            }
	            else if (press_time >= SHORT_PRESS_MS)
	            {
	                btn->flags.short_press = 1U;
	                log_printf(LOG_DEBUG, "btn: short_press");
	            }
	        }

	        log_printf(LOG_DEBUG, "button state: %s",
	                   state ? "PRESSED" : "RELEASED");
	    }

	    return state;
}




