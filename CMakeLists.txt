cmake_minimum_required(VERSION 3.15)
project(fillit C)

set(CMAKE_C_STANDARD 99)

add_executable(fillit main.c field.h field.c figure.c figure.h main_algorithm.c main_algorithm.h fill_print_final_result.c fill_print_final_result.h validate.c validate.h)