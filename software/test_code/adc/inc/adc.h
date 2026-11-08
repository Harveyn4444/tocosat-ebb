#ifndef _ADC_H
#define _ADC_H

//Custom code to streamline functions using the RP2040 internal adc


#include "pico/stdlib.h"
#include "hardware/adc.h"

#ifdef __cplusplus
extern "C" {
#endif


float measure_vsys();
float measure_pico_temperature();

#ifdef __cplusplus
}
#endif


#endif
