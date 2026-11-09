#ifndef _APP_HOUSEKEEPING_H
#define _APP_HOUSEKEEPING_H

#include <stdint.h>
#include "../inc/config.h"
#include "../inc/adc.h"
#include "../libs/pico-lm75/lm75.h"

#ifdef __cplusplus
extern "C" {
#endif


SPACECRAFT_STATE app_housekeeping(void);


#ifdef __cplusplus
}
#endif


#endif