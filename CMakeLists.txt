cmake_minimum_required(VERSION 3.10)

project(machine-learning)

file(GLOB SOURCES "src/*.c")
file(GLOB HEADERS "include/*.h")

add_library(machine-learning SHARED ${SOURCES} ${HEADERS})
target_include_directories(machine-learning PUBLIC include)