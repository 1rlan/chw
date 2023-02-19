cmake_minimum_required(VERSION 3.21)
project(chw)

set(CMAKE_CXX_STANDARD 20)

add_executable(chw main.cpp
        sorts/merge_sort.cpp
        sorts/selection_sort.cpp
        sorts/insertion_sort.cpp
        sorts/counting_sort.cpp
        sorts/quick_sort.cpp
        sorts/bubble_sort.cpp
        sorts/bubble_sort_1.cpp
        sorts/shell_sort.cpp
        sorts/insertion_binary_sort.cpp
        sorts/shell_sort_ciura.cpp
        generations/generators.cpp
        sorts/sorts.h
        generations/generators.h tools/tools.cpp tools/tools.h sorts/bubble_sort_1+2.cpp sorts/digit_sort.cpp sorts/heap_sort.cpp sorts_run/sorts_run.cpp sorts_run/sorts_run.h)
