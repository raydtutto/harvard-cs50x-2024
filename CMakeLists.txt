cmake_minimum_required(VERSION 3.27)
project(harvard_cs50x_2024 C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(thirdparty/cs50)

# Adding target hello
add_executable(hello
        src/week_1/problem_set_set1/hello.c)
# Link cs50.h
target_link_libraries(hello PUBLIC cs50x)

add_executable(hello_with_name
        src/week_1/hello_with_name.c)
target_link_libraries(hello_with_name PUBLIC cs50x)

add_executable(compare
        src/week_1/compare.c)
target_link_libraries(compare PUBLIC cs50x)

add_executable(agree
        src/week_1/agree.c)
target_link_libraries(agree PUBLIC cs50x)

add_executable(meow
        src/week_1/meow.c)

add_executable(calculator
        src/week_1/calculator.c)
target_link_libraries(calculator PUBLIC cs50x)

add_executable(mario src/week_1/mario.c)
target_link_libraries(mario PUBLIC cs50x)
