cmake_minimum_required(VERSION 3.10)

project(machine-learning)

set(CORE src/core)
set(LINEAR_ALGEBRA src/linear_algebra)

add_subdirectory(${CORE})
add_subdirectory(${LINEAR_ALGEBRA})