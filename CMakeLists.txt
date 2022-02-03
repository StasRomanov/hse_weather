cmake_minimum_required(VERSION 3.21)
project(hse_weather C)

set(CMAKE_C_STANDARD 23)

add_executable(hse_weather main.c api/weatherJson.c api/weatherJson.h util/wearherData/functions.c util/wearherData/functions.h api/util/system/settings.c api/util/system/settings.h)
