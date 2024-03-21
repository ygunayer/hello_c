cmake_minimum_required(VERSION 3.25)
project(hello_c)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

add_executable(${PROJECT_NAME} src/main.c)
