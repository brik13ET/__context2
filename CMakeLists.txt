cmake_minimum_required(VERSION 3.21)
# THIS HAS TO COME BEFORE THE PROJECT LINE
set(CMAKE_C_COMPILER "gcc")
project(__context2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)


add_executable(
        c_asm

        C_asm.c
        C_asm.s
)
add_executable(
        pureC

        pureC.c
)
add_executable(
        pureCPP

        pureCPP.cpp
)
add_executable(
        gen_header

        header_gen.c
)

add_compile_options(
        -fno-builtin-sqrt
        -fno-builtin-memcpy
)





