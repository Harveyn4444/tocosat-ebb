# Blink

This project introduces initialising and controlling the voltages of the microcontroller's GPIO pins. This project simply initialises GPIO pins as outputs and turns them on once the spacecraft finishes initialising. 
This project builds upon the `states` project example.

## Compile the code
Make a build directory
```bash
mkdir build
cd build
```
Run Cmake
```bash
cmake ..
```
Then make
```bash
make -j4
```
## RP2040
Copy into the project the pico C SDK cmake file:
```bash
cp ~/pico-sdk/external/pico_sdk_import.cmake .
```

Make a build directory
```bash
mkdir build
cd build
```
Export your local path to the installed C SDK, replace `PATH-TO`.
```bash
export PICO_SDK_PATH=PATH-TO/pico-sdk
```
Run Cmake
```bash
cmake ..
```
Then make
```bash
make -j4
```

Put the RP2040 into boot mode and then upload with: replace `USERNAME`
```bash
cp PROJECT_NAME.uf2 /media/USERNAME/RPI-RP2/
```


## clang Formatter
Run:
```bash
clang-format -i FILENAME.c
```
