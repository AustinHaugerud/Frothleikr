cmake_minimum_required(VERSION 3.3)
project(Frothleikr)

set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS}")

file(GLOB FTR_HEADERS include/*.h)
file(GLOB FTR_SOURCE src/*.c)
add_library(Frothleikr STATIC ${FTR_SOURCE} ${FTR_HEADERS})

include_directories(include)

add_subdirectory(examples)
add_subdirectory(tests)

