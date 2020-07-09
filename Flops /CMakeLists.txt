cmake_minimum_required(VERSION 3.0)
project(max-flops LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(measure_flops flops.cc)