/*
    This project creates states for the spacecraft, which determine the operations of the spacecraft at a given time. 
    This example introduces the STARTUP, IDLE and HOUSEKEEPING states.  



*/


#include <stdio.h>
#include <stdint.h>   //C99 allows for definitions like uint8_t

#include "config.h"

#include "app/app_startup.h"

#include "pico/stdlib.h"	//Default pico lib

int main(){

    spacecraft_state = app_startup();
    printf("Spacecraft State %d \n" , spacecraft_state);

    while(1){
        switch (spacecraft_state){
            case (STARTUP):
                //spacecraft_state = app_startup();
                break;
            case (IDLE):
                break;
            case (HOUSEKEEPING):
                break;
            case (ERROR):
                break;
            default:
                printf("Error Incorrect State");
                while(1);
                break;
        }
    }
    return 0;
}