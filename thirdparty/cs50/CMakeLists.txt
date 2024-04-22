cmake_minimum_required(VERSION 3.27)
project(cs50x C)

set(CMAKE_C_STANDARD 11)

add_library(cs50x SHARED include/cs50.h include/cs50.c)
target_include_directories(cs50x PUBLIC include)
