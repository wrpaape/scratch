set(SMALLEST_CIRCLE_INCLUDE_DIRECTORIES ${PROJECT_INCLUDE_DIR}
                                        ${CMAKE_CURRENT_LIST_DIR})
set(SMALLEST_CIRCLE_LIBRARIES           smallest_circle)

include_directories(${SMALLEST_CIRCLE_INCLUDE_DIRECTORIES})

add_library(parse_points    OBJECT parse_points.c)
add_library(smallest_circle STATIC smallest_circle.c)

add_executable(
    find_smallest_circle
    find_smallest_circle.c
    $<TARGET_OBJECTS:parse_points>
)
target_link_libraries(find_smallest_circle ${SMALLEST_CIRCLE_LIBRARIES})

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
