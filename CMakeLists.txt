cmake_minimum_required(VERSION 3.27)
project(harvard_cs50x_2024 C)

set(CMAKE_C_STANDARD 11)

# Include cs50.h
include_directories($ENV{C_INCLUDE_PATH})

# Adding target hello
add_executable(hello
        src/week_1/hello.c)
add_executable(hello_with_name
        src/week_1/hello_with_name.c)

# Link cs50.h
target_link_libraries(hello_with_name cs50)