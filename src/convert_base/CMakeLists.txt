include(have_c_array_range_initializer)

set(CONVERT_BASE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_LIST_DIR})
set(CONVERT_BASE_LIBRARIES           m)

include_directories(${CONVERT_BASE_INCLUDE_DIRECTORIES})

if(${HAVE_C_ARRAY_RANGE_INITIALIZER})
    set(get_digit_source get_digit.c)
else()
    set(get_digit_source codegen/get_digit.c)
    # generate the 'base_map' lookup definitions source file
    add_executable(generate_get_digit generate_get_digit.c)
    add_custom_command(
        OUTPUT            ${get_digit_source}
        COMMAND           generate_get_digit ${get_digit_source}
        COMMENT           "generating ${get_digit_source}"
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    )
endif()

add_library(get_digit      OBJECT ${get_digit_source})
add_library(get_max_digits OBJECT get_max_digits.c)
add_library(add            OBJECT add.c)
add_library(multiply       OBJECT multiply.c)
add_library(convert_base   OBJECT convert_base.c)

add_executable(
    base_converter
    base_converter.cpp
    $<TARGET_OBJECTS:convert_base>
    $<TARGET_OBJECTS:get_digit>
    $<TARGET_OBJECTS:get_max_digits>
    $<TARGET_OBJECTS:add>
    $<TARGET_OBJECTS:multiply>
)
target_link_libraries(base_converter ${CONVERT_BASE_LIBRARIES})

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
