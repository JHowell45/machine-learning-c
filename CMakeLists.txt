cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME machine-learning)

project(${PROJECT_NAME})

if (NOT DEFINED ENV{CUSTOM_C_LIBRARY_DEST})
    message(FATAL_ERROR "Please set the CUSTOM_C_LIBRARY_DEST environment variable!")
endif()

set(LIBRARY_DEST $ENV{CUSTOM_C_LIBRARY_DEST}/${PROJECT_NAME})

message("\n############################################# SETUP #############################################\n")
message(LIBRARY_DEST: ${LIBRARY_DEST})
message("\n#################################################################################################\n")

file(GLOB SOURCES "src/*.c")
file(GLOB HEADERS "include/*.h")

####################################################################################
#  Library:
####################################################################################

add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC include)

####################################################################################
#  Examples:
####################################################################################
set(EXAMPLES_DIR examples)

# add_executable(example_2_1 ${EXAMPLES_DIR}/example_2_1.c)
# target_link_libraries(example_2_1 ${PROJECT_NAME})

####################################################################################
#  Tests:
####################################################################################
set(TESTS_DIR tests)

add_executable(test_create_vector ${TESTS_DIR}/test_create_vector.c)
target_link_libraries(test_create_vector ${PROJECT_NAME})

enable_testing()

add_test(
    NAME test_create_vector
    COMMAND test_create_vector
)

####################################################################################
#  Installation:
####################################################################################
install(TARGETS ${PROJECT_NAME} DESTINATION ${LIBRARY_DEST}/lib)
install(FILES ${HEADERS} DESTINATION ${LIBRARY_DEST}/include)