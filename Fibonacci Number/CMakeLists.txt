#cmake_minimum_required(VERSION 3.0)
cmake_minimum_required(VERSION 3.1.3)
project(FIB)

add_definitions(-std=c++11)
set(APP_SRC main.cpp)
set(LIB_SRC fibonacci.cc)
add_library(lib_fib ${LIB_SRC})

add_executable(fib ${APP_SRC})
target_link_libraries(fib lib_fib)
#set_target_properties(liblib_fib PROPERTIES OUTPUT_NAME "fib")
set_target_properties(lib_fib PROPERTIES OUTPUT_NAME "fib")
