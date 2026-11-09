
#include "app_housekeeping.h"




SPACECRAFT_STATE app_housekeeping(void){

    // Periodically updates a counter
    if( (uint64_t)( msSinceBoot - previous_telemetry_update) >= housekeeping_telemetry_interval){

        //Read ADC Readings
        pico_internal_temperature = measure_pico_temperature();
        
        housekeeping_counter++;

        gpio_put(LED_PIN_2 , LED_2_state);    // Turns LED on
        
        // Toggles LED each Interval
        if(LED_2_state == 0){
            LED_2_state = 1;
        } else {
            LED_2_state = 0;
        }

        // Reading onboard local LM75
        main_onboard_temperature = LM75_ReadTemperature(i2c0, MAIN_LM75_ADDR);

        pcf8520_read_raw(i2c0 , MAIN_RTC_ADDR, raw_time);
        pcf8520_convert_time(real_time, raw_time);

        printf("%02d:%02d:%02d ", real_time[2], real_time[1], real_time[0]);
        printf("%02d/%02d/%02d ", real_time[3], real_time[5], real_time[6]);
       

        printf("HOUSEKEEPING %d | pico Temperature %.2f | onboard Temperature %.2f C \n" , housekeeping_counter , pico_internal_temperature , main_onboard_temperature);
        previous_telemetry_update = msSinceBoot;
    }

    return HOUSEKEEPING;
}