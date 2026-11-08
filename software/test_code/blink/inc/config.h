#ifndef _CONFIG_H
#define _CONFIG_H

//Global variables
//They are declared here but need to be defined in a .c file
#include <stdio.h>
#include <stdint.h>   //C99 allows for definitions like uint8_t

#include "pico/stdlib.h"	//Default pico lib

#ifdef __cplusplus
extern "C" {
#endif



typedef enum {
    STARTUP = 0,
    IDLE = 1,
    HOUSEKEEPING = 2,

    ERROR = 99
} SPACECRAFT_STATE;

// uint8_t spacecraft_state = 0;

extern SPACECRAFT_STATE spacecraft_state;

#define LED_PIN_1 26
#define LED_PIN_2 27 

extern uint8_t LED_1_state;
extern uint8_t LED_2_state;

#ifdef __cplusplus
}
#endif


#endif