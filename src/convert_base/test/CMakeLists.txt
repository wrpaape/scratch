add_google_test(
    NAME                test_convert_base
    SOURCES             test_convert_base.cpp
                        $<TARGET_OBJECTS:convert_base>
    INCLUDE_DIRECTORIES ${CONVERT_BASE_INCLUDE_DIRECTORIES}
)
