
#include "app_housekeeping.h"




SPACECRAFT_STATE app_housekeeping(void){

    // Periodically updates a counter
    if( (uint64_t)( msSinceBoot - previous_telemetry_update) >= housekeeping_telemetry_interval){

        //Read ADC Readings
        onboard_temperature = measure_pico_temperature();
        
        housekeeping_counter++;

        gpio_put(LED_PIN_2 , LED_2_state);    // Turns LED on
        
        // Toggles LED each Interval
        if(LED_2_state == 0){
            LED_2_state = 1;
        } else {
            LED_2_state = 0;
        }

        printf("HOUSEKEEPING %d | onboard Temperature %.2f C \n" , housekeeping_counter , onboard_temperature);
        previous_telemetry_update = msSinceBoot;
    }

    return HOUSEKEEPING;
}