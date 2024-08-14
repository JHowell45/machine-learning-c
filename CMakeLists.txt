cmake_minimum_required(VERSION 3.15)

project(machine-learning)

if (NOT DEFINED ENV{CUSTOM_C_LIBRARY_DEST})
    message(FATAL_ERROR "Please set the CUSTOM_C_LIBRARY_DEST environment variable!")
endif()

set(LIBRARY_DEST $ENV{CUSTOM_C_LIBRARY_DEST})

message("\n############################################# SETUP #############################################\n")
message(LIBRARY_DEST: ${LIBRARY_DEST})
message("\n#################################################################################################\n")

file(GLOB SOURCES "src/*.c")
file(GLOB HEADERS "include/*.h")

####################################################################################
#  Library:
####################################################################################

add_library(machine-learning SHARED ${SOURCES} ${HEADERS})
target_include_directories(machine-learning PUBLIC include)

####################################################################################
#  Examples:
####################################################################################
set(EXAMPLES_DIR examples)

add_executable(example_2_1 ${EXAMPLES_DIR}/example_2_1.c)
target_link_libraries(example_2_1 machine-learning)

####################################################################################
#  Tests:
####################################################################################
set(TESTS_DIR tests)

add_executable(test_vector ${TESTS_DIR}/test_vector.c)
target_link_libraries(test_vector machine-learning)

enable_testing()

add_test(
    NAME test_vector
    COMMAND test_vector
)

####################################################################################
#  Installation:
####################################################################################
install(TARGETS machine-learning DESTINATION ${LIBRARY_DEST}/lib)
install(FILES ${HEADERS} DESTINATION ${LIBRARY_DEST}/include)