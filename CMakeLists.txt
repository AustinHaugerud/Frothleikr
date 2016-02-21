cmake_minimum_required(VERSION 3.3)
project(Frothleikr)

set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS}")

file(GLOB FTR_HEADERS *.h)
file(GLOB FTR_SOURCE *.c)
add_library(Frothleikr ${FTR_SOURCE} ${FTR_HEADERS})

add_subdirectory(examples)

