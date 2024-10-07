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

add_executable(temps_insertion
        src/week_3_algorithms/additional_practice/temps/temps_insertion.c)
target_link_libraries(temps_insertion PUBLIC cs50x)

add_executable(max
        src/week_3_algorithms/additional_practice/max.c)
target_link_libraries(max PUBLIC cs50x)

add_executable(snackbar
        src/week_3_algorithms/additional_practice/snackbar.c)
target_link_libraries(snackbar PUBLIC cs50x)

add_executable(addresses
        src/week_4_memory/notes/src/addresses.c)
target_link_libraries(addresses PUBLIC cs50x)

add_executable(w4_compare
        src/week_4_memory/notes/src/w4_compare.c)
target_link_libraries(w4_compare PUBLIC cs50x)

add_executable(copy_1
        src/week_4_memory/notes/src/copy/copy_1.c)
target_link_libraries(copy_1 PUBLIC cs50x)

add_executable(copy_2
        src/week_4_memory/notes/src/copy/copy_2.c)
target_link_libraries(copy_2 PUBLIC cs50x)

add_executable(copy_3
        src/week_4_memory/notes/src/copy/copy_3.c)
target_link_libraries(copy_3 PUBLIC cs50x)

add_executable(copy_4
        src/week_4_memory/notes/src/copy/copy_4.c)
target_link_libraries(copy_4 PUBLIC cs50x)

add_executable(memory
        src/week_4_memory/notes/src/memory.c)
target_link_libraries(memory PUBLIC cs50x)

add_executable(swap
        src/week_4_memory/notes/src/swap.c)
target_link_libraries(swap PUBLIC cs50x)

add_executable(get_int
        src/week_4_memory/notes/src/get/get_int.c)

add_executable(get_string
        src/week_4_memory/notes/src/get/get_string.c)

add_executable(phonebook
        src/week_4_memory/notes/src/phonebook.c)
target_link_libraries(phonebook PUBLIC cs50x)

add_executable(cp
        src/week_4_memory/notes/src/cp.c)

add_executable(pdf
        src/week_4_memory/notes/src/pdf.c)
target_link_libraries(pdf PUBLIC cs50x)

add_executable(volume
        src/week_4_memory/problem_set_4/volume/volume.c)

add_executable(filter
        src/week_4_memory/problem_set_4/filter-less/filter.c
        src/week_4_memory/problem_set_4/filter-less/helpers.c
        src/week_4_memory/problem_set_4/filter-less/helpers.h
        src/week_4_memory/problem_set_4/filter-less/bmp.h)

add_executable(test_filters self-test/ps4/test_filters.c)

add_executable(filter-more
        src/week_4_memory/problem_set_4/filter-more/filter-more.c
        src/week_4_memory/problem_set_4/filter-more/bmp.h
        src/week_4_memory/problem_set_4/filter-more/helpers.c
        src/week_4_memory/problem_set_4/filter-more/helpers.h)

add_executable(recover
        src/week_4_memory/problem_set_4/recover/recover.c)

add_executable(bottomup
        src/week_4_memory/additional_practice/bottomup/bottomup.c
        src/week_4_memory/additional_practice/bottomup/bmp.h)

add_executable(license
        src/week_4_memory/additional_practice/license/license.c)

add_executable(list_1
        src/week_5_data_structures/notes/src/list/list_1.c)

add_executable(list_2
        src/week_5_data_structures/notes/src/list/list_2.c)

add_executable(list_3
        src/week_5_data_structures/notes/src/list/list_3.c)
target_link_libraries(list_3 PUBLIC cs50x)

add_executable(list_4
        src/week_5_data_structures/notes/src/list/list_4.c)
target_link_libraries(list_4 PUBLIC cs50x)

add_executable(list_5
        src/week_5_data_structures/notes/src/list/list_5.c)
target_link_libraries(list_5 PUBLIC cs50x)

add_executable(list_6
        src/week_5_data_structures/notes/src/list/list_6.c)
target_link_libraries(list_6 PUBLIC cs50x)

add_executable(section_list
        src/week_5_data_structures/notes/src/section/section_list.c)
target_link_libraries(section_list PUBLIC cs50x)

add_executable(section_table
        src/week_5_data_structures/notes/src/section/section_table.c)
target_link_libraries(section_table PUBLIC cs50x)

add_executable(inheritance src/week_5_data_structures/problem_set_5/inheritance.c)

add_executable(speller
        src/week_5_data_structures/problem_set_5/speller/speller.c
        src/week_5_data_structures/problem_set_5/speller/dictionary.c
        src/week_5_data_structures/problem_set_5/speller/dictionary.h)

add_executable(trie
        src/week_5_data_structures/additional_practice/trie/trie.c)
target_link_libraries(trie PUBLIC cs50x)
