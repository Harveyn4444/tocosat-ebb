#include "app_startup.h"



SPACECRAFT_STATE app_startup(void){

    stdio_init_all();
    adc_init();

    sleep_ms(3000);  // Wait 3 seconds for USB serial to enumerate

    //Initilaising GPIO
    //LED_1 pin also assigned to ADC input channel 4.
	// gpio_init(LED_PIN_1);
    // gpio_set_dir(LED_PIN_1, GPIO_OUT);

    gpio_init(LED_PIN_2);
    gpio_set_dir(LED_PIN_2, GPIO_OUT);

    //gpio_put(LED_PIN_1 , 0);    // Turns LED off
    gpio_put(LED_PIN_2 , 0);    // Turns LED off

    LED_1_state = 0;
    LED_2_state = 0;


	//Initialise I2C port at 400 kHz
    i2c_init(i2c0, 400 * 1000);

    // Initialise I2C pins
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);

    // Starting/resetting the RTC 
    // Currently does not enable battery 
    // pcf8520_reset();
    pcf8520_reset(i2c0 , MAIN_RTC_ADDR);

    // Only as a test 
    pcf820_write_current_time(i2c0 , MAIN_RTC_ADDR);    // Writes to a define struct inside the function



    //Reading and reporting the LM75 default configuration
    // This will be moved to pico-lm75/lm75.c

    uint8_t REG_CONFIG = 0x01;
    uint8_t data[1] = {0};
    reg_read(i2c0, MAIN_LM75_ADDR, REG_CONFIG, data, 1);
    printf("Config register: 0x%02X\r\n", data[0]);





    printf("STARTUP \n");


    return IDLE;   //May return state
}