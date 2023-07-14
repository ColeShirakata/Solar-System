#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace renderer {

    struct Shader {
        GLuint UnlitUniformID;
    };

    int init();
    GLFWwindow* getWindow();
    void renderAll();
    void preRender();
    void framebuffer_size_callback(GLFWwindow* window, int width, int height);

    extern GLFWwindow* window;
    extern GLuint FramebufferID;
    extern Shader shader;
}