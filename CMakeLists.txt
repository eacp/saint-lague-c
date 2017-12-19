cmake_minimum_required(VERSION 3.9)
project(saint_lague C)

set(CMAKE_C_STANDARD 11)

add_executable(sl main.c data.c data.h saint_lague.c saint_lague.h)