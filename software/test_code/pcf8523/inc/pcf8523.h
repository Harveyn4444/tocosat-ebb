#ifndef _PCF8523_H
#define _PCF8523_H

// #include "pico/stdlib.h"
// #include "hardware/i2c.h"
// #include <stdint.h>
// #include "config.h"

#ifdef __cplusplus
extern "C" {
#endif


// I want to pass in the i2c instance and address
void pcf8520_reset(i2c_inst_t *i2c_inst , uint8_t device_address );

void pcf820_write_current_time(i2c_inst_t *i2c_inst , uint8_t device_address ); 


void pcf8520_read_raw(i2c_inst_t *i2c_inst , uint8_t device_address, uint8_t *buffer); 
void pcf8520_convert_time(int conv_time[7], const uint8_t raw_time[7]); 

#ifdef __cplusplus
}
#endif


#endif