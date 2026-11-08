#include "adc.h"

float measure_pico_temperature(){

    adc_set_temp_sensor_enabled(true); //changes the internal circuitry to turn on the internl analogue temperature sensor and route the adc channel
    adc_gpio_init(26);
    //Connected to ADC4
    adc_select_input(4);
    
    // 12-bit conversion, assume max value == ADC_VREF == 3.3 V
    uint16_t raw = adc_read();
    float voltage = raw * 3.3f/(1<<12);
    float measure_pico_temperature = 27 - (voltage - 0.706)/0.001721;

    return measure_pico_temperature;
}