if(NOT BUILD_TESTING)
    return()
endif()
include(have_c_array_range_initializer)

set(CONVERT_BASE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_LIST_DIR})

include_directories(${CONVERT_BASE_INCLUDE_DIRECTORIES})


if(${HAVE_C_ARRAY_RANGE_INITIALIZER})
    set(get_digit get_digit.c)
else()
    set(get_digit codegen/get_digit.c)
    # generate the 'base_map' lookup definitions source file
    add_executable(generate_get_digit generate_get_digit.c)
    add_custom_command(
        OUTPUT            ${get_digit}
        COMMAND           generate_get_digit ${get_digit}
        COMMENT           "generate get_digit.c"
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    )
endif()

add_library(convert_base OBJECT convert_base.c ${get_digit})

add_subdirectory(test)
