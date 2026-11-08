# States

This project introduces the ideas of spacecraft sates. Depending on the state of the spacecraft, different blocks of code will run. These blocks of code are referred to as apps, meaning its current application it is working on.

They are located in `/app` an are named `app_DESCRIPTION`, where `DESCRIPTION` should explain in a single word if possible the use of the application.
For the project the apps introduced are `app_startup`, `app_idle` and `app_housekeeping`.







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
