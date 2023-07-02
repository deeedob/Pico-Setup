cmake_minimum_required(VERSION 3.25)

# Specify the location of the sdk
set(PICO_SDK_PATH /usr/share/pico-sdk)
include(pico_sdk_import.cmake)

project(rpiPICOStarter LANGUAGES ASM C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra)

# Treat warnings as errors
option(WarningsAreErrors "Treat warnings as errors" ON)
if (WarningsAreErrors)
    add_compile_options(-Werror)
endif()

add_subdirectory(${PICO_SDK_PATH} pico-sdk)

set(TARGET rpi_pico_starter)

add_executable(${TARGET} main.cpp)
target_link_libraries(${TARGET} pico_stdlib)

pico_enable_stdio_usb(${TARGET} 1)
pico_enable_stdio_uart(${TARGET} 0)
# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(${TARGET})

# upload to the pico
find_program(PICOTOOL_COMMAND picotool)

add_custom_target(
  rpi_upload_project
  COMMAND ${PICOTOOL_COMMAND} load ${CMAKE_CURRENT_BINARY_DIR}/${TARGET}.uf2 -f
  COMMENT "Uploading to PICO"
  DEPENDS ${TARGET}
)

