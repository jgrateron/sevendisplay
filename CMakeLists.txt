cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(sevendisplay)
enable_language( C CXX ASM )

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

if (TARGET tinyusb_device)

add_executable(sevendisplay
    sevendisplay.c
)

# Add pico_stdlib library which aggregates commonly used features
target_include_directories(sevendisplay PRIVATE ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/..)

target_link_libraries(sevendisplay pico_stdlib)

pico_enable_stdio_usb(sevendisplay 1)
pico_enable_stdio_uart(sevendisplay 0)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(sevendisplay)

elseif(PICO_ON_DEVICE)
    message(WARNING "not building hello_usb because TinyUSB submodule is not initialized in the SDK")
endif()
