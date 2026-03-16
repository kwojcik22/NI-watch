/*
 * manager.c
 *
 *  Created on: 16 mar 2026
 *      Author: kwojcik
 */
#include <stdint.h>
#include "stm32f0xx_hal.h"
#include "Manager/Flags.h"
#include "bsp/buttons.h"
#include "gpio.h"

extern button_t Button_BLUE;
 uint8_t hh = 0;
 uint8_t mm = 0;
void MainMachine(void){

}

uint8_t SetTimeMachine(menu_flags_t *flags){
	hh = 0;
	if(flags->set_time_h){
		Button_Pressed(&Button_BLUE);
		if(Button_BLUE.flags.short_press){ // if enter
			hh = 1U;
		}
	}
}

uint8_t SetAlarmMachine(button_t *btn){

}

uint8_t delay_nonblocking(uint32_t *timer, uint32_t delay)
{
    if (HAL_GetTick() - *timer >= delay)
    {
        *timer = HAL_GetTick();
        return 1;
    }
    return 0;
}
