#include "config.h"


SPACECRAFT_STATE spacecraft_state = STARTUP;

uint64_t msSinceBoot = 0;

uint64_t idle_start_timestamp = 0;
uint64_t idle_state_update_timestamp = 0;

uint8_t LED_1_state = 0;
uint8_t LED_2_state = 0;


// Telemetry
uint16_t housekeeping_telemetry_interval = 1000;
uint16_t housekeeping_counter = 0;
uint64_t previous_telemetry_update = 0;

float main_onboard_temperature = 0;

uint8_t raw_time[7] = {0};
int real_time[7] = {0};

float pico_internal_temperature = 0;