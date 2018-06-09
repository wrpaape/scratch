if(PROJECT_CMAKE_HAVE_C_ARRAY_RANGE_INITIALIZER_INCLUDED)
    return()
endif()
set(PROJECT_CMAKE_HAVE_C_ARRAY_RANGE_INITIALIZER_INCLUDED TRUE)
# ==============================================================================
# check C++ compiler's support for range initialization extension keyword
# set HAVE_C_ to that keyword or empty string if not supported
# ==============================================================================
# External API
# ------------------------------------------------------------------------------
function(set_have_c_array_range_initializer)
    set(bin_dir ${PROJECT_CMAKE_BIN_DIR})
    set(src_dir ${PROJECT_CMAKE_SRC_DIR}/have_c_array_range_initializer)
    try_run(
        exit_code
        compiled
        ${bin_dir}
        ${src_dir}/test_have_c_array_range_initializer.c
    )

    # check if range initializers compile and work as expected
    if(compiled AND ("${exit_code}" EQUAL 0))
        set(have_c_array_range_initializer TRUE)
    else()
        set(have_c_array_range_initializer FALSE)
    endif()

    set(HAVE_C_ARRAY_RANGE_INITIALIZER ${have_c_array_range_initializer} PARENT_SCOPE)
endfunction()

set_have_c_array_range_initializer()
