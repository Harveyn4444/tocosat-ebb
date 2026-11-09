#ifndef _APP_STARTUP_H
#define _APP_STARTUP_H

#include <stdint.h>
#include "hardware/i2c.h"
#include "../inc/config.h"
#include "../inc/pcf8523.h"
#include "../libs/pico-lm75/lm75.h"

#ifdef __cplusplus
extern "C" {
#endif


// Code goes here
SPACECRAFT_STATE app_startup(void);


#ifdef __cplusplus
}
#endif


#endif