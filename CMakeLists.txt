cmake_minimum_required(VERSION 3.27)
project(harvard_cs50x_2024 C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(thirdparty/cs50)

# Adding target hello
add_executable(hello
        src/week_1/problem_set_1/me/hello.c)
# Link cs50.h
target_link_libraries(hello PUBLIC cs50x)

add_executable(hello_with_name
        src/week_1/src/hello_with_name.c)
target_link_libraries(hello_with_name PUBLIC cs50x)

add_executable(compare
        src/week_1/src/compare.c)
target_link_libraries(compare PUBLIC cs50x)

add_executable(agree
        src/week_1/src/agree.c)
target_link_libraries(agree PUBLIC cs50x)

add_executable(meow
        src/week_1/src/meow.c)

add_executable(calculator
        src/week_1/src/calculator.c)
target_link_libraries(calculator PUBLIC cs50x)

add_executable(mario
        src/week_1/src/mario.c)
target_link_libraries(mario PUBLIC cs50x)

add_executable(mario-less
        src/week_1/problem_set_1/mario-less/mario.c)
target_link_libraries(mario-less PUBLIC cs50x)

add_executable(mario-more
        src/week_1/problem_set_1/mario-more/mario.c)
target_link_libraries(mario-more PUBLIC cs50x)

add_executable(debug
        src/week_1/additional_practice/debug/debug.c)
target_link_libraries(debug PUBLIC cs50x)

add_executable(cash
        src/week_1/problem_set_1/cash/cash.c)
target_link_libraries(cash PUBLIC cs50x)

add_executable(credit
        src/week_1/problem_set_1/credit/credit.c)
target_link_libraries(credit PUBLIC cs50x)

add_executable(half
        src/week_1/additional_practice/half/half.c)
target_link_libraries(half PUBLIC cs50x)

add_executable(prime
        src/week_1/additional_practice/prime/prime.c)
target_link_libraries(prime PUBLIC cs50x)
