cmake_minimum_required(VERSION 3.14)
project(exercise05 LANGUAGES CXX)

find_package(Catch2 QUIET)
if (NOT Catch2_FOUND)
  include(FetchContent)

  FetchContent_Declare(
      catch2
      GIT_REPOSITORY https://github.com/catchorg/Catch2.git
      GIT_TAG        v2.11.0
  )

  FetchContent_MakeAvailable(catch2)
  list(APPEND CMAKE_MODULE_PATH "${catch2_SOURCE_DIR}/contrib")
endif()

include(CTest)
include(Catch)

add_subdirectory(palindrome)
add_subdirectory(h_index)
add_subdirectory(msw)
