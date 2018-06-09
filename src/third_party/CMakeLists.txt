cmake_minimum_required(VERSION 2.8.2 FATAL_ERROR) # ExternalProject
project(third_party)

include(ExternalProject)

# GLFW
# ------------------------------------------------------------------------------
ExternalProject_Add(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw
    GIT_TAG        latest
    SOURCE_DIR     ${CMAKE_CURRENT_LIST_DIR}/glfw
    INSTALL_DIR    ${CMAKE_INSTALL_PREFIX}
    CMAKE_ARGS     -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
                   -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}
)

# GLAD
# ------------------------------------------------------------------------------
ExternalProject_Add(
    glad
    GIT_REPOSITORY https://github.com/Dav1dde/glad
    GIT_TAG        master
    SOURCE_DIR     ${CMAKE_CURRENT_LIST_DIR}/glad
    INSTALL_DIR    ${CMAKE_INSTALL_PREFIX}
    CMAKE_ARGS     -DGLAD_GENERATOR=c
                   -DGLAD_SPEC=gl
                   -DGLAD_INSTALL=ON
                   -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
                   -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}
)
