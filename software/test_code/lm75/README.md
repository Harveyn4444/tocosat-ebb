# lm75









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
## Adding a submodule
To add a git submodule use the command
```bash
git submodule add https://github.com/user/repo.git path/to/submodule
```
To clone the submodule, once cloned run 
```bash
git clone --recurse-submodules <repository-url>
```