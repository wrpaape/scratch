# third_party
# ------------------------------------------------------------------------------
include(add_third_party)
add_third_party(
    NAME "third party dependencies"
    INSTALL_PREFIX ${PROJECT_SOURCE_DIR}
)

# find artifacts
find_package(glfw REQUIRED CONFIG NAMES glfw3)
find_package(glad REQUIRED CONFIG)


# scratch programs
# ------------------------------------------------------------------------------
add_subdirectory(convert_base)
add_subdirectory(learn_opengl)
