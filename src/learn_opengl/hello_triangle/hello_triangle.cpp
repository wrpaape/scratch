#include <cstdlib>      // exit()
#include <cmath>        // sin()
#include <iostream>     // std::cerr|cout|endl
#include <iterator>     // std::size
#include <glad/glad.h>  // gl*
#include <GLFW/glfw3.h> // glfw*


namespace {

static const int WIDTH  = 800;
static const int HEIGHT = 600;

// rectangle
static const float rect_vertices[] = {
    +0.5f, +0.5f, 0.0f, // top right
    +0.5f, -0.5f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f, // bottom left
    -0.5f, +0.5f, 0.0f  // top left
};
static const unsigned int rect_indices[] = {
    0, 1, 3, // first triangle
    1, 2, 3  // second triangle
};

static const float corners[] = {
    -0.9f, +0.9f, 0.0f, // top left
    -0.9f, +0.6f, 0.0f,
    -0.6f, +0.9f, 0.0f,
    -0.9f, -0.9f, 0.0f, // bottom left
    -0.9f, -0.6f, 0.0f,
    -0.6f, -0.9f, 0.0f,
    +0.9f, +0.9f, 0.0f, // top right
    +0.9f, +0.6f, 0.0f,
    +0.6f, +0.9f, 0.0f,
    +0.9f, -0.9f, 0.0f, // bottom right
    +0.9f, -0.6f, 0.0f,
    +0.6f, -0.9f, 0.0f
};


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

inline GLFWwindow *create_window()
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

    return window;
}

template <std::size_t size>
unsigned int compile_shader(unsigned int shader_type,
                            const char (&source)[size])
{
    const char *first   = &source[0];
    int length          = size - 1;
    unsigned int shader = glCreateShader(shader_type);
    glShaderSource(shader, 1, &first, &length);
    glCompileShader(shader);

    int compiled;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    if (!compiled) {
        char failure[512];
        glGetShaderInfoLog(shader, sizeof(failure), nullptr, failure);
        exit_on_failure(failure, 3);
    }

    return shader;
}

template<typename ...Shaders>
unsigned int create_shader_program(Shaders... shaders)
{
    unsigned int shader_program = glCreateProgram();

    (glAttachShader(shader_program, shaders), ...);

    glLinkProgram(shader_program);

    int linked;
    glGetProgramiv(shader_program, GL_LINK_STATUS, &linked);
    if (!linked) {
        char failure[512];
        glGetProgramInfoLog(shader_program, sizeof(failure), nullptr, failure);
        exit_on_failure(failure, 4);
    }

    return shader_program;
}

template<typename ...Shaders>
void delete_shaders(Shaders... shaders)
{
    (glDeleteShader(shaders), ...);
}


inline void process_input(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

inline int get_uniform(int         shader_program,
                       const char *name)
{
    int uniform = glGetUniformLocation(shader_program, name);
    if (uniform == -1)
        exit_on_failure("glGetUniformLocation() failure", 5);

    return uniform;
}

} // namespace


int main()
{
    GLFWwindow *window = create_window();

    // compile the vertex shader
    unsigned int vertex_shader = compile_shader(
        GL_VERTEX_SHADER,
        "\n# version 330 core"
        "\nlayout (location = 0) in vec3 aPos;"
        "\n"
        "\nvoid main()"
        "\n{"
        "\n    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 2.0);"
        "\n}"
    );

    // compile the fragment shader
    unsigned int orange_fragment_shader = compile_shader(
        GL_FRAGMENT_SHADER,
        "\n# version 330 core"
        "\nout vec4 FragColor;"
        "\n"
        "\nvoid main()"
        "\n{"
        "\n    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);"
        "\n}"
    );

    // compile the yellow fragment shader
    unsigned int yellow_fragment_shader = compile_shader(
        GL_FRAGMENT_SHADER,
        "\n# version 330 core"
        "\nout vec4 FragColor;"
        "\nuniform float alpha;"
        "\n"
        "\nvoid main()"
        "\n{"
        "\n    FragColor = vec4(1.0f, 1.0f, 0.0f, alpha);"
        "\n}"
    );

    // link the shaders
    unsigned int shader_program = create_shader_program(vertex_shader,
                                                        orange_fragment_shader);

    unsigned int yellow_shader_program = create_shader_program(vertex_shader,
                                                               yellow_fragment_shader);

    delete_shaders(vertex_shader, orange_fragment_shader, yellow_fragment_shader);

    // grab the "alpha" uniform
    int alpha_uniform = get_uniform(yellow_shader_program, "alpha");

    // create the vertex array, vertex buffer, and element buffer objects
    unsigned int vertex_arrays[2];
    glGenVertexArrays(2, vertex_arrays);
    unsigned int rect_vao    = vertex_arrays[0];
    unsigned int corners_vao = vertex_arrays[1];

    unsigned int buffers[3];
    glGenBuffers(3, buffers);
    unsigned int rect_vbo    = buffers[0];
    unsigned int rect_ebo    = buffers[1];
    unsigned int corners_vbo = buffers[2];

    // rectangle
    //--------------------------------------------------------------------------
    // bind the vertex array object first...
    glBindVertexArray(rect_vao);
    // then bind the vertex buffer...
    glBindBuffer(GL_ARRAY_BUFFER, rect_vbo);
    // then set the vertex buffer...
    glBufferData(GL_ARRAY_BUFFER, sizeof(rect_vertices), rect_vertices, GL_STATIC_DRAW);
    // then bind the element buffer...
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rect_ebo);
    // then set the element buffer...
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(rect_indices), rect_indices, GL_STATIC_DRAW);
    // // then configure the vertex attributes...
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
    // unbind the vertex buffer and vertex array (zero unbinds the currently bound object)
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // corners
    // --------------------------------------------------------------------------
    // bind the vertex array object first...
    glBindVertexArray(corners_vao);
    // then bind the vertex buffer...
    glBindBuffer(GL_ARRAY_BUFFER, corners_vbo);
    // then set the vertex buffer...
    glBufferData(GL_ARRAY_BUFFER, sizeof(corners), corners, GL_STATIC_DRAW);
    // then configure the vertex attributes...
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
    // unbind the vertex buffer and vertex array (zero unbinds the currently bound object)
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // turn on wireframe mode
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // render loop
    while (!glfwWindowShouldClose(window)) {
        // check for escape
        process_input(window);

        // color the background
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw the rectangle
        glUseProgram(shader_program);
        glBindVertexArray(rect_vao);
        // glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawElements(GL_TRIANGLES, std::size(rect_indices), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        // draw the corners
        glUseProgram(yellow_shader_program);
        glBindVertexArray(corners_vao);
        // glDrawArrays(GL_TRIANGLES, 0, 12);
        glDrawArrays(GL_TRIANGLES, 0, std::size(corners));
        glBindVertexArray(0);

        // update the uniform alpha
        float alpha = (sin(glfwGetTime()) / 2.0) + 0.5;
        glUniform1f(alpha_uniform, alpha);

        // check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // free vertex buffer and vertex array
    glDeleteBuffers(std::size(buffers),            buffers);
    glDeleteVertexArrays(std::size(vertex_arrays), vertex_arrays);

    // free GLFW resources and exit
    glfwTerminate();
    return 0;
}
