cmake_minimum_required(VERSION 3.25)

project(cxxopts)

option(CXXOPTS_BUILD_TESTS "Build api tests" OFF)

set(CXXOPTS_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CXXOPTS_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(src)

if(CXXOPTS_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
