cmake_minimum_required(VERSION 3.1.3)
project(mem_moun LANGUAGES CXX)

find_package(OpenMP)

add_executable(mm mm.cc)
target_compile_features(mm PRIVATE cxx_std_17)
if(OpenMP_CXX_FOUND)
  target_link_libraries(mm OpenMP::OpenMP_CXX)
endif()
