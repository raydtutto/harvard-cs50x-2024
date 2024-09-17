cmake_minimum_required(VERSION 3.27)
project(harvard_cs50x_2024 C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(thirdparty/cs50)

# Adding targets
add_executable(hello_world
        src/week_1_c/problem_set_1/world/hello.c)

add_executable(hello
        src/week_1_c/problem_set_1/me/hello.c)
# Link cs50.h
target_link_libraries(hello PUBLIC cs50x)

add_executable(hello_with_name
        src/week_1_c/notes/src/hello_with_name.c)
target_link_libraries(hello_with_name PUBLIC cs50x)

add_executable(compare
        src/week_1_c/notes/src/compare.c)
target_link_libraries(compare PUBLIC cs50x)

add_executable(agree
        src/week_1_c/notes/src/agree.c)
target_link_libraries(agree PUBLIC cs50x)

add_executable(meow
        src/week_1_c/notes/src/meow.c)

add_executable(calculator
        src/week_1_c/notes/src/calculator.c)
target_link_libraries(calculator PUBLIC cs50x)

add_executable(mario
        src/week_1_c/notes/src/mario.c)
target_link_libraries(mario PUBLIC cs50x)

add_executable(mario-less
        src/week_1_c/problem_set_1/mario-less/mario.c)
target_link_libraries(mario-less PUBLIC cs50x)

add_executable(mario-more
        src/week_1_c/problem_set_1/mario-more/mario.c)
target_link_libraries(mario-more PUBLIC cs50x)

add_executable(debug
        src/week_1_c/additional_practice/debug/debug.c)
target_link_libraries(debug PUBLIC cs50x)

add_executable(cash
        src/week_1_c/problem_set_1/cash/cash.c)
target_link_libraries(cash PUBLIC cs50x)

add_executable(credit
        src/week_1_c/problem_set_1/credit/credit.c)
target_link_libraries(credit PUBLIC cs50x)

add_executable(half
        src/week_1_c/additional_practice/half/half.c)
target_link_libraries(half PUBLIC cs50x)

add_executable(prime
        src/week_1_c/additional_practice/prime/prime.c)
target_link_libraries(prime PUBLIC cs50x)

add_executable(scores1
        src/week_2_arrays/notes/src/scores/scores1.c)
target_link_libraries(scores1 PUBLIC cs50x)

add_executable(scores2
        src/week_2_arrays/notes/src/scores/scores2.c)
target_link_libraries(scores2 PUBLIC cs50x)

add_executable(scores3
        src/week_2_arrays/notes/src/scores/scores3.c)
target_link_libraries(scores3 PUBLIC cs50x)

add_executable(hi1
        src/week_2_arrays/notes/src/hi/hi1.c)

add_executable(hi2
        src/week_2_arrays/notes/src/hi/hi2.c)
target_link_libraries(hi2 PUBLIC cs50x)

add_executable(hi3
        src/week_2_arrays/notes/src/hi/hi3.c)
target_link_libraries(hi3 PUBLIC cs50x)

add_executable(length1
        src/week_2_arrays/notes/src/length/length1.c)
target_link_libraries(length1 PUBLIC cs50x)

add_executable(length2
        src/week_2_arrays/notes/src/length/length2.c)
target_link_libraries(length2 PUBLIC cs50x)

add_executable(string1
        src/week_2_arrays/notes/src/string/string1.c)
target_link_libraries(string1 PUBLIC cs50x)

add_executable(string2
        src/week_2_arrays/notes/src/string/string2.c)
target_link_libraries(string2 PUBLIC cs50x)

add_executable(string3
        src/week_2_arrays/notes/src/string/string3.c)
target_link_libraries(string3 PUBLIC cs50x)

add_executable(uppercase1
        src/week_2_arrays/notes/src/uppercase/uppercase1.c)
target_link_libraries(uppercase1 PUBLIC cs50x)

add_executable(uppercase2
        src/week_2_arrays/notes/src/uppercase/uppercase2.c)
target_link_libraries(uppercase2 PUBLIC cs50x)

add_executable(uppercase3
        src/week_2_arrays/notes/src/uppercase/uppercase3.c)
target_link_libraries(uppercase3 PUBLIC cs50x)

add_executable(greet1
        src/week_2_arrays/notes/src/greet/greet1.c)
target_link_libraries(greet1 PUBLIC cs50x)

add_executable(greet2
        src/week_2_arrays/notes/src/greet/greet2.c)
target_link_libraries(greet2 PUBLIC cs50x)

add_executable(greet3
        src/week_2_arrays/notes/src/greet/greet3.c)
target_link_libraries(greet3 PUBLIC cs50x)

add_executable(double
        src/week_2_arrays/notes/src/section/double.c)
target_link_libraries(double PUBLIC cs50x)

add_executable(alphabetical
        src/week_2_arrays/notes/src/section/alphabetical.c)
target_link_libraries(alphabetical PUBLIC cs50x)

add_executable(argv
        src/week_2_arrays/notes/src/section/argv.c)
target_link_libraries(argv PUBLIC cs50x)

add_executable(scrabble
        src/week_2_arrays/problem_set_2/scrabble.c)
target_link_libraries(scrabble PUBLIC cs50x)

add_executable(readability
        src/week_2_arrays/problem_set_2/readability.c)
target_link_libraries(readability PUBLIC cs50x)

add_executable(caesar
        src/week_2_arrays/problem_set_2/caesar.c)
target_link_libraries(caesar PUBLIC cs50x)

add_executable(substitution
        src/week_2_arrays/problem_set_2/substitution.c)
target_link_libraries(substitution PUBLIC cs50x)
add_executable(hours
        src/week_2_arrays/additional_practice/hours.c)
target_link_libraries(hours PUBLIC cs50x)

add_executable(no-vowels
        src/week_2_arrays/additional_practice/no-vowels.c)
target_link_libraries(no-vowels PUBLIC cs50x)

add_executable(no-vowels_2
        src/week_2_arrays/additional_practice/no-vowels_2.c)
target_link_libraries(no-vowels_2 PUBLIC cs50x)

add_executable(password
        src/week_2_arrays/additional_practice/password.c)
target_link_libraries(password PUBLIC cs50x)

add_executable(search
        src/week_3_algorithms/notes/src/search.c)
target_link_libraries(search PUBLIC cs50x)

add_executable(search_string
        src/week_3_algorithms/notes/src/search_string.c)
target_link_libraries(search_string PUBLIC cs50x)

add_executable(phonebook_1
        src/week_3_algorithms/notes/src/phonebook_1.c)
target_link_libraries(phonebook_1 PUBLIC cs50x)

add_executable(phonebook_2
        src/week_3_algorithms/notes/src/phonebook_2.c)
target_link_libraries(phonebook_2 PUBLIC cs50x)

add_executable(iteration
        src/week_3_algorithms/notes/src/iteration.c
        src/week_3_algorithms/notes/src/search_candidate.c)
target_link_libraries(iteration PUBLIC cs50x)

add_executable(recursion
        src/week_3_algorithms/notes/src/recursion.c)
target_link_libraries(recursion PUBLIC cs50x)

add_executable(search_candidate
        src/week_3_algorithms/notes/src/search_candidate.c)
target_link_libraries(search_candidate PUBLIC cs50x)

add_executable(factorial
        src/week_3_algorithms/notes/src/factorial.c)
target_link_libraries(factorial PUBLIC cs50x)

add_executable(plurality
        src/week_3_algorithms/problem_set_3/plurality.c)
target_link_libraries(plurality PUBLIC cs50x)

add_executable(runoff
        src/week_3_algorithms/problem_set_3/runoff.c)
target_link_libraries(runoff PUBLIC cs50x)

add_executable(test_hello
        self-test/ps1/test_hello.c)
target_link_libraries(test_hello PUBLIC cs50x)

add_executable(test_hello_me
        self-test/ps1/test_hello_me.c)
target_link_libraries(test_hello_me PUBLIC cs50x)

add_executable(test_mario_less
        self-test/ps1/test_mario_less.c)
target_link_libraries(test_mario_less PUBLIC cs50x)

add_executable(test_mario_more
        self-test/ps1/test_mario_more.c)
target_link_libraries(test_mario_more PUBLIC cs50x)

add_executable(test_cash
        self-test/ps1/test_cash.c)
target_link_libraries(test_cash PUBLIC cs50x)

add_executable(test_credit
        self-test/ps1/test_credit.c)
target_link_libraries(test_credit PUBLIC cs50x)

add_executable(test_half
        self-test/ps1/test_half.c)
target_link_libraries(test_half PUBLIC cs50x)

add_executable(test_scrabble
        self-test/ps2/test_scrabble.c)
target_link_libraries(test_scrabble PUBLIC cs50x)

add_executable(test_readability
        self-test/ps2/test_readability.c)
target_link_libraries(test_readability PUBLIC cs50x)

add_executable(test_caesar
        self-test/ps2/test_caesar.c)
target_link_libraries(test_caesar PUBLIC cs50x)

add_executable(test_substitution
        self-test/ps2/test_substitution.c)
target_link_libraries(test_substitution PUBLIC cs50x)

add_executable(test_plurality
        self-test/ps3/test_plurality.c)
target_link_libraries(test_plurality PUBLIC cs50x)

add_executable(test_runoff
        self-test/ps3/test_runoff.c)
target_link_libraries(test_runoff PUBLIC cs50x)

add_executable(tideman
        src/week_3_algorithms/problem_set_3/tideman.c)
target_link_libraries(tideman PUBLIC cs50x)

add_executable(atoi
        src/week_3_algorithms/additional_practice/atoi.c)
target_link_libraries(atoi PUBLIC cs50x)

add_executable(temps_bubble
        src/week_3_algorithms/additional_practice/temps/temps_bubble.c)
target_link_libraries(temps_bubble PUBLIC cs50x)

add_executable(temps_selection
        src/week_3_algorithms/additional_practice/temps/temps_selection.c)
target_link_libraries(temps_selection PUBLIC cs50x)
