add_google_test(
    NAME                test_smallest_circle
    SOURCES             test_smallest_circle.cpp
    INCLUDE_DIRECTORIES ${SMALLEST_CIRCLE_INCLUDE_DIRECTORIES}
    LIBRARIES           ${SMALLEST_CIRCLE_LIBRARIES}
)

add_google_test(
    NAME                test_parse_points
    SOURCES             test_parse_points.cpp
                        $<TARGET_OBJECTS:parse_points>
    INCLUDE_DIRECTORIES ${SMALLEST_CIRCLE_INCLUDE_DIRECTORIES}
)
