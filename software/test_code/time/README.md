# time

This project introduces the idea of time for the satellite. The RP2040 and most microcontrollers are able to track the time since boot. This is useful but also has a limit before the value overflows and the time also resets upon every boot. This can be useful for the initial events upon startup, but for events like scheduling a different time reference is required. This time reference can be provided from a GPS signal, onboard real time clock or the time can be set from an RF link.

This project introduces reading the onboard time since boot and uses it to trigger events and state changes of the spacecraft. This builds upon the `states` and `blink` examples.

To introduce the idea of onboard time, time intervals are introduced, having the s/c boot and then remain in the IDLE state for 5 seconds where it will then change its state to housekeeping. The use of delays() or sleep_m() are absolutely avoided.

## Future Work
The RP2040 has an onboard RTC module, which does not retain the time between restarts. This could be useful for setting the time from a radio telecommand. The use of a GPS requires an actual GPS module, which gain can set the reference time and can be periodically checked and updated. Again this can be done periodically or by a radio telecommand. The use of an actual RTC module, which keeps power by the use of its own battery, also takes load away from the microcontroller needing to constantly update its internal time. This is the option chosen for the TocoSat EBB, which also has a GPS module. After the working RF, RTC and GPS examples, an RF telecommand to sync the RTC time to a GPS signal will be shown.

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
