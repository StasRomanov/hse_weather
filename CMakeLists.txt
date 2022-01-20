cmake_minimum_required(VERSION 3.21)
project(loader C)

set(CMAKE_C_STANDARD 23)

add_executable(loader main.c api/weatherJson.c api/weatherJson.h)
