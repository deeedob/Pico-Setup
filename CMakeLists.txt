cmake_minimum_required(VERSION 3.25)

# Specify the location of the sdk
set(PICO_SDK_PATH /usr/share/pico-sdk)
include(pico_sdk_import.cmake)

project(rpiPICOStarter LANGUAGES ASM C CXX)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(rpiPICOStarter main.cpp)

target_link_libraries(rpiPICOStarter pico_stdlib)

pico_enable_stdio_usb(rpiPICOStarter 1)
pico_enable_stdio_uart(rpiPICOStarter 0)
# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(rpiPICOStarter)