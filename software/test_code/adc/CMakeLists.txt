 cmake_minimum_required(VERSION 3.18)

include(pico_sdk_import.cmake)

# Replace PROJECT_NAME
project(adc C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(${PROJECT_NAME}
    adc.c
    inc/config.c
    inc/adc.c
    app/app_startup.c
    app/app_housekeeping.c
   )

target_include_directories(${PROJECT_NAME} PRIVATE
    inc
    app
    )

target_link_libraries(${PROJECT_NAME}
     pico_stdlib
     hardware_adc
    )

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

pico_add_extra_outputs(${PROJECT_NAME})