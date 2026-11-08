#include "app_startup.h"



SPACECRAFT_STATE app_startup(void){

    stdio_init_all();
    sleep_ms(3000);  // Wait 3 seconds for USB serial to enumerate

    printf("STARTUP\n");


    return IDLE;   //May return state
}