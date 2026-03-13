set(CMAKE_VERSION_MINIMUM 3.31)
cmake_minimum_required(VERSION ${CMAKE_VERSION_MINIMUM})
message(STATUS "Cmake version: ${CMAKE_VERSION} (>= ${CMAKE_VERSION_MINIMUM} ✓)")

# Compiler version check
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if (WIN32)
        message(FATAL_ERROR
                "Detected the use of MinGW GCC compiler on Windows.\n"
                "MinGW GCC has serious compatibility issues with C++23 modules (import std).\n"
                "Please switch to Clang (such as llvm-mingw) or MSVC for compilation."
        )
    endif ()
    set(COMPILER_GCC_VERSION_MINIMUM 14.0)
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS ${COMPILER_GCC_VERSION_MINIMUM})
        message(FATAL_ERROR
                "GCC version too old for C++ Modules.\n"
                "GCC version: ${CMAKE_CXX_COMPILER_VERSION} (>= ${COMPILER_GCC_VERSION_MINIMUM} X)"
        )
    else()
        message(STATUS "GCC version: ${CMAKE_CXX_COMPILER_VERSION} (>= ${COMPILER_GCC_VERSION_MINIMUM} ✓)")
    endif()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(COMPILER_CLANG_VERSION_MINIMUM 17.0)
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS ${COMPILER_CLANG_VERSION_MINIMUM})
        message(FATAL_ERROR
                "Clang version too old for C++ Modules.\n"
                "Clang version: ${CMAKE_CXX_COMPILER_VERSION} (>= ${COMPILER_CLANG_VERSION_MINIMUM} X)"
        )
    else()
        message(STATUS "Clang version: ${CMAKE_CXX_COMPILER_VERSION} (>= ${COMPILER_CLANG_VERSION_MINIMUM} ✓)")
    endif()
elseif (MSVC)
    set(COMPILER_MSVC_VERSION_MINIMUM 1934)
    if (MSVC_VERSION LESS ${COMPILER_MSVC_VERSION_MINIMUM})
        message(FATAL_ERROR
                "MSVC version too old for C++ Modules.\n"
                "MSVC version: ${CMAKE_CXX_COMPILER_VERSION} (>= ${COMPILER_MSVC_VERSION_MINIMUM} X)"
        )
    else()
        message(STATUS "MSVC version: ${MSVC_VERSION} (>= ${COMPILER_MSVC_VERSION_MINIMUM} ✓)")
    endif()
endif()

# Find CMAKE_EXPERIMENTAL_CXX_IMPORT_STD UUID
# https://github.com/Kitware/CMake/blob/master/Help/dev/experimental.rst
string(REGEX REPLACE "-[A-Za-z0-9_]+$" "" CMAKE_VER_FULL "${CMAKE_VERSION}")
file(READ "${CMAKE_CURRENT_LIST_DIR}/cmake_import_std_uuids.json" _json_str)
string(REGEX MATCH "\"${CMAKE_VER_FULL}\"[ \t]*:[ \t]*\"([0-9a-fA-F\\-]+)\"" _match "${_json_str}")
if(_match)
    string(REGEX REPLACE ".*\"${CMAKE_VER_FULL}\"[ \t]*:[ \t]*\"([0-9a-fA-F\\-]+)\".*" "\\1" _uuid "${_match}")
    message(STATUS "Detected CMake version ${CMAKE_VER_FULL}, using import_std UUID = ${_uuid}")
    set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "${_uuid}")
else()
    string(REGEX MATCH "\"default\"[ \t]*:[ \t]*\"([0-9a-fA-F\\-]+)\"" _default_match "${_json_str}")

    if(_default_match)
        string(REGEX REPLACE ".*\"default\"[ \t]*:[ \t]*\"([0-9a-fA-F\\-]+)\".*" "\\1" _uuid "${_default_match}")
        message(STATUS "CMake version ${CMAKE_VER_FULL} not found in mapping, forcing default UUID = ${_uuid}")
    else()
        message(FATAL_ERROR "Default UUID not found in cmake_import_std_uuids.json — cannot proceed without import std configuration")
    endif()
endif()

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