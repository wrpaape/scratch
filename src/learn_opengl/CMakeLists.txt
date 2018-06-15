find_package(OpenGL 3.3 REQUIRED)
include_directories(SYSTEM ${OPENGL_INCLUDE_DIR})
link_libraries(glad::glad glfw ${OPENGL_LIBRARIES})


add_subdirectory(hello_window)
add_subdirectory(hello_triangle)
