cmake_minimum_required(VERSION 3.0)

project(quicksort)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

file(GLOB QUICKSORT_SRCS "quicksort.c" "quicksort.h")
file(GLOB TEST_SRCS "test.c")

add_library(quicksort SHARED ${QUICKSORT_SRCS})

add_executable(demo ${TEST_SRCS})

target_link_libraries(demo quicksort)