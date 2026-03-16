/*
 * Flags.h
 *
 *  Created on: 18 lut 2026
 *      Author: kwojcik
 */

#ifndef INC_MANAGER_FLAGS_H_
#define INC_MANAGER_FLAGS_H_

typedef union
{
    struct
    {
        uint8_t alarm_en     	: 1;
        uint8_t alarm_on    	: 1;
        uint8_t set_alarm_h 	: 1;
        uint8_t set_alarm_m  	: 1;
        uint8_t set_time_h      : 1;
        uint8_t set_time_m    	: 1;
        uint8_t reserved		: 2;
    };
    uint8_t raw;
} menu_flags_t;

menu_flags_t MainMenu;

#endif /* INC_MANAGER_FLAGS_H_ */
