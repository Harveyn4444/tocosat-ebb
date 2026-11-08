#ifndef _CONFIG_H
#define _CONFIG_H

//Global variables
//They are declared here but need to be defined in a .c file
#include <stdint.h>   //C99 allows for definitions like uint8_t
#include <stdio.h>
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


// time
extern uint64_t msSinceBoot;
extern uint64_t idle_start_timestamp;
extern uint64_t idle_state_update_timestamp;

// Housekeeping Telemetry
extern uint16_t housekeeping_telemetry_interval;
extern uint64_t previous_telemetry_update;
extern uint16_t housekeeping_counter;

#ifdef __cplusplus
}
#endif


#endif