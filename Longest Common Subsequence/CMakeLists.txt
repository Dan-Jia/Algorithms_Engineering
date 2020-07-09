cmake_minimum_required(VERSION 3.1.3)
project(LCS)

add_definitions(-std=c++11)
set(APP_SRC test.cc)
set(LIB_SRC lcs.cc)
add_library(lib_lcs ${LIB_SRC})
add_library(catch INTERFACE)

add_executable(lcs ${APP_SRC})
target_link_libraries(lcs lib_lcs catch)
enable_testing()
add_test(NAME mytest COMMAND lcs)
