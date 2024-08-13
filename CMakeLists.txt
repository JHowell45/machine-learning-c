cmake_minimum_required(VERSION 3.15)

project(machine-learning)

file(GLOB SOURCES "src/*.c")
file(GLOB HEADERS "include/*.h")

####################################################################################
#  Library:
####################################################################################

add_library(machine-learning SHARED ${SOURCES} ${HEADERS})
target_include_directories(machine-learning PUBLIC include)

####################################################################################
#  Tests:
####################################################################################
set(TEST_DIR tests)

add_executable(test_vector ${TEST_DIR}/test_vector.c)
target_link_libraries(test_vector machine-learning)

enable_testing()

add_test(
    NAME test_vector
    COMMAND test_vector
)