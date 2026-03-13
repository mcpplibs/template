set(CMAKE_VERSION_MINIMUM 3.31)
cmake_minimum_required(VERSION ${CMAKE_VERSION_MINIMUM})
message(STATUS "Cmake version: ${CMAKE_VERSION} (>= ${CMAKE_VERSION_MINIMUM} ✓)")

# https://github.com/Kitware/CMake/blob/master/Help/dev/experimental.rst
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "a9e1cf81-9932-4810-974b-6eccaf14e457")
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_MODULE_STD 1)

project(mcpplibs-templates VERSION 1.0.0 LANGUAGES CXX)

# Library
add_library(mcpplibs-templates STATIC)

file(GLOB_RECURSE MODULE_SOURCES "src/*.cppm")

target_sources(mcpplibs-templates
    PUBLIC
        FILE_SET CXX_MODULES FILES
        ${MODULE_SOURCES}
)

# Example
add_executable(basic examples/basic.cpp)
target_link_libraries(basic PRIVATE mcpplibs-templates)

# Test
option(BUILD_TESTING "Build the testing directories" ON)

if (BUILD_TESTING)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()