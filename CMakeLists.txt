cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)
set(CMAKE_CXX_STANDARD 17)
project(pico_libraries)


pico_sdk_init()

add_subdirectory(gps)
add_subdirectory(imu)