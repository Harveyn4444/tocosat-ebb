#include "app_startup.h"



SPACECRAFT_STATE app_startup(void){

    stdio_init_all();
    sleep_ms(3000);  // Wait 3 seconds for USB serial to enumerate

    //Initilaising GPIO
	gpio_init(LED_PIN_1);
    gpio_set_dir(LED_PIN_1, GPIO_OUT);

    gpio_init(LED_PIN_2);
    gpio_set_dir(LED_PIN_2, GPIO_OUT);

    gpio_put(LED_PIN_1 , 0);    // Turns LED off
    gpio_put(LED_PIN_2 , 0);    // Turns LED off

    LED_1_state = 0;
    LED_2_state = 0;




    printf("STARTUP \n");


    return IDLE;   //May return state
}