add_google_test(
    NAME                test_convert_base
    SOURCES             test_convert_base.cpp
                        $<TARGET_OBJECTS:convert_base>
                        $<TARGET_OBJECTS:get_digit>
    INCLUDE_DIRECTORIES ${CONVERT_BASE_INCLUDE_DIRECTORIES}
)

add_google_test(
    NAME                test_get_digit
    SOURCES             test_get_digit.cpp
                        $<TARGET_OBJECTS:get_digit>
    INCLUDE_DIRECTORIES ${CONVERT_BASE_INCLUDE_DIRECTORIES}
)
