set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/vector.c)
set(HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/vector.h)

add_library(core ${SRC})
target_include_directories(core PUBLIC ${HEADERS})