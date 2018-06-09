#include <cstdlib>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace {

static const int WIDTH  = 800;
static const int HEIGHT = 600;

[[noreturn]] inline void exit_on_failure(const char *failure,
                                         int         exit_status)
{
    std::cerr << failure << std::endl;
    glfwTerminate();
    exit(exit_status);
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height); // update viewport on window resize
}

inline void process_input(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

} // namespace

int main()
{
    if (!glfwInit())
        exit_on_failure("glfwInit() failure", 1);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,        GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif

    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT,
                                          "LearnOpenGL", nullptr, nullptr);
    if (window == NULL)
        exit_on_failure("glfwCreateWindow() failure", 2);

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
        exit_on_failure("gladLoadGLLoader() failure", 3);

    glViewport(0, 0, WIDTH, HEIGHT);

    (void) glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // render loop
    while (!glfwWindowShouldClose(window)) {
        // input
        process_input(window);

        // rendering
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
