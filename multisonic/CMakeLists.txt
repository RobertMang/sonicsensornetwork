cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME multisonic)
project(${PROJECT_NAME})

set(${CMAKE_PROJECT_NAME}_SKETCH multisonic.ino)
generate_arduino_firmware(${CMAKE_PROJECT_NAME})
