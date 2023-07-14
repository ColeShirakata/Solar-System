#include "renderer.h"

GLFWwindow* renderer::window;
GLuint renderer::FramebufferID;
renderer::Shader renderer::shader;

void renderer::preRender() {
    glBindFramebuffer(GL_FRAMEBUFFER, FramebufferID);

    GLenum drawbuffers[2] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1 };
    glDrawBuffers(2, drawbuffers);
    glUniform1i(shader.UnlitUniformID, 0);

    glClearColor(0.1f, 0.2f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
}

void renderer::renderAll() {
    preRender();
}

GLFWwindow* renderer::getWindow() {
    return window;
}

void renderer::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

// Sets up environment
int renderer::init() {
    std::cout << "Init start" << std::endl;

    // Initializes GLFW
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);


    // Creates window
    window = glfwCreateWindow(1280, 720, "Universe", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Changes the context to the new window
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize glad" << std::endl;
        return -1;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    return 1;
}