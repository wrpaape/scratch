cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(
    scratch
    VERSION 0.1.0
    LANGUAGES CXX C
)

# cmake options
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_CXX_STANDARD     17)
set(CMAKE_C_STANDARD       11)
option(BUILD_TESTING "Enable unit testing." ON)

# global directories
set(PROJECT_SRC_DIR          ${PROJECT_SOURCE_DIR}/src)
set(PROJECT_INCLUDE_DIR      ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_BUILD_DIR        ${PROJECT_SOURCE_DIR}/build)
set(PROJECT_BIN_DIR          ${PROJECT_SOURCE_DIR}/bin)
set(PROJECT_LIB_DIR          ${PROJECT_SOURCE_DIR}/lib)
set(PROJECT_TEST_DIR         ${PROJECT_SOURCE_DIR}/test)
set(PROJECT_CMAKE_DIR        ${PROJECT_SOURCE_DIR}/cmake)
set(PROJECT_CMAKE_MODULE_DIR ${PROJECT_CMAKE_DIR}/module)

# make cmake modules available to CMAKE_MODULE_PATH
list(APPEND CMAKE_MODULE_PATH ${PROJECT_CMAKE_MODULE_DIR})

# set up common cmake module environment
include(cmake_environ)

# set up project testing environment
# to disable unit testing, invoke cmake with '-DBUILD_TESTING=OFF' from the
# command line or set BUILD_TESTING to OFF in the interactive GUI (if supported)
if(BUILD_TESTING)
    include(test_environ)
    add_subdirectory(test)
endif()

# enter
add_subdirectory(src)