add_google_test(
    NAME                test_get_digit
    SOURCES             test_get_digit.cpp
                        $<TARGET_OBJECTS:get_digit>
    INCLUDE_DIRECTORIES ${CONVERT_BASE_INCLUDE_DIRECTORIES}
)

add_google_test(
    NAME                test_get_max_digits
    SOURCES             test_get_max_digits.cpp
                        $<TARGET_OBJECTS:get_max_digits>
    LIBRARIES           m
)

add_google_test(
    NAME                test_add
    SOURCES             test_add.cpp
                        $<TARGET_OBJECTS:add>
    INCLUDE_DIRECTORIES ${CONVERT_BASE_INCLUDE_DIRECTORIES}
)

add_google_test(
    NAME                test_multiply
    SOURCES             test_multiply.cpp
                        $<TARGET_OBJECTS:multiply>
    INCLUDE_DIRECTORIES ${CONVERT_BASE_INCLUDE_DIRECTORIES}
)

add_google_test(
    NAME                test_convert_base
    SOURCES             test_convert_base.cpp
    INCLUDE_DIRECTORIES ${CONVERT_BASE_INCLUDE_DIRECTORIES}
    LIBRARIES           ${CONVERT_BASE_LIBRARIES}
)
