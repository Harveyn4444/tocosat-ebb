/*
  PCF8523, this project will set the tie to ..... and then repeat back the tmie peridocially for the telemetry update



*/


#include <stdio.h>
#include <stdint.h>   //C99 allows for definitions like uint8_t

#include "config.h"

#include "app/app_startup.h"
#include "app/app_housekeeping.h"

#include "pico/stdlib.h"	//Default pico lib

uint16_t idle_change_state_interval = 5000;  // Temporary Variable for this example, 5 seconds.
bool idle_state_started = false;

int main(){
    msSinceBoot = to_ms_since_boot(get_absolute_time());

    spacecraft_state = app_startup();
    printf("Spacecraft State %d \n" , spacecraft_state);

    while(1){
        msSinceBoot = to_ms_since_boot(get_absolute_time());

        switch (spacecraft_state){
            case (STARTUP):
                // Should not reach this state after initial Startup

                break;
            case (IDLE):
                //Checking if 5 seconds has passed since the IDLE state was entered 
                
                // Checks if IDLE state was entered for the first time
                if(idle_state_started == false){
                    idle_start_timestamp = to_ms_since_boot(get_absolute_time());
                    idle_state_started = true;

                    // Setting both LEDs HIGH to indicate IDLE state has been reached
                    //Pin now used for ADC
                    //gpio_put(LED_PIN_1 , 1);    // Turns LED on

                }
                    
                if( (uint64_t)(idle_state_update_timestamp - idle_start_timestamp) >= idle_change_state_interval ){
                    idle_state_started = false;
                    spacecraft_state = HOUSEKEEPING;
                } else {
                    idle_state_update_timestamp = to_ms_since_boot(get_absolute_time());
                }

                break;
            case (HOUSEKEEPING):
                    app_housekeeping();
                break;
            case (ERROR):
                break;
            default:
                printf("Error Incorrect State");
                while(1);
                break;
        }
    }
    return 0;
}