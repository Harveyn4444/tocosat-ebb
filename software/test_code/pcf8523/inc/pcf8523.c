/*
Example code taken and adpated from:
https://github.com/raspberrypi/pico-examples/blob/master/i2c/pcf8523_i2c/pcf8523_i2c.c

*/

#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include <stdint.h>
#include "config.h"
#include "pcf8523.h"


// void pcf8520_reset() {
void pcf8520_reset(i2c_inst_t *i2c_inst , uint8_t device_address ){

    // Two byte reset. First byte register, second byte data
    // There are a load more options to set up the device in different ways that could be added here
    uint8_t buf[] = {0x00, 0x58};
    // i2c_write_blocking(i2c_default, addr, buf, 2, false);
    // i2c_write_blocking(i2c0, MAIN_RTC_ADDR, buf, 2, false);
    i2c_write_blocking(i2c_inst, device_address, buf, 2, false);

    
}

void pcf820_write_current_time(i2c_inst_t *i2c_inst , uint8_t device_address ) {
    // buf[0] is the register to write to
    // buf[1] is the value that will be written to the register
    uint8_t buf[2];

    //Write values for the current time in the array
    //index 0 -> second: bits 4-6 are responsible for the ten's digit and bits 0-3 for the unit's digit
    //index 1 -> minute: bits 4-6 are responsible for the ten's digit and bits 0-3 for the unit's digit
    //index 2 -> hour: bits 4-5 are responsible for the ten's digit and bits 0-3 for the unit's digit
    //index 3 -> day of the month: bits 4-5 are responsible for the ten's digit and bits 0-3 for the unit's digit
    //index 4 -> day of the week: where Sunday = 0x00, Monday = 0x01, Tuesday... ...Saturday = 0x06
    //index 5 -> month: bit 4 is responsible for the ten's digit and bits 0-3 for the unit's digit
    //index 6 -> year: bits 4-7 are responsible for the ten's digit and bits 0-3 for the unit's digit

    //NOTE: if the value in the year register is a multiple for 4, it will be considered a leap year and hence will include the 29th of February

    // This is the time to fill in to set to
    // uint8_t current_val[7] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    // Setting to 9/11/2026 21:00
    uint8_t current_val[7] = {0x00, 0x00, 0x21, 0x09, 0x01, 0x11, 0x26};

    for (int i = 3; i < 10; ++i) {
        buf[0] = i;
        buf[1] = current_val[i - 3];
        // i2c_write_blocking(i2c0, MAIN_RTC_ADDR, buf, 2, false);
        i2c_write_blocking(i2c_inst, device_address, buf, 2, false);
    }
}
 
void pcf8520_read_raw(i2c_inst_t *i2c_inst , uint8_t device_address, uint8_t *buffer) {
    // For this particular device, we send the device the register we want to read
    // first, then subsequently read from the device. The register is auto incrementing
    // so we don't need to keep sending the register we want, just the first.

    // Start reading acceleration registers from register 0x3B for 6 bytes
    uint8_t val = 0x03;
    // i2c_write_blocking(i2c0, MAIN_RTC_ADDR, &val, 1, true); // true to keep master control of bus
    // i2c_read_blocking(i2c0, MAIN_RTC_ADDR, buffer, 7, false);
    i2c_write_blocking(i2c_inst, device_address, &val, 1, true); // true to keep master control of bus
    i2c_read_blocking(i2c_inst, device_address, buffer, 7, false);
}

void pcf8520_convert_time(int conv_time[7], const uint8_t raw_time[7]) {
    // Convert raw data into time
    conv_time[0] = (10 * (int) ((raw_time[0] & 0x70) >> 4)) + ((int) (raw_time[0] & 0x0F));
    conv_time[1] = (10 * (int) ((raw_time[1] & 0x70) >> 4)) + ((int) (raw_time[1] & 0x0F));
    conv_time[2] = (10 * (int) ((raw_time[2] & 0x30) >> 4)) + ((int) (raw_time[2] & 0x0F));
    conv_time[3] = (10 * (int) ((raw_time[3] & 0x30) >> 4)) + ((int) (raw_time[3] & 0x0F));
    conv_time[4] = (int) (raw_time[4] & 0x07);
    conv_time[5] = (10 * (int) ((raw_time[5] & 0x10) >> 4)) + ((int) (raw_time[5] & 0x0F));
    conv_time[6] = (10 * (int) ((raw_time[6] & 0xF0) >> 4)) + ((int) (raw_time[6] & 0x0F));
}