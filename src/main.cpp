#include "rendering/renderer.h"

#include <iostream>

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

int main() {
    // Calls renderer to initialize window
    if (!renderer::init()) {
        std::cout << "Failed to initialize renderer" << std::endl;
        return -1;
    }

    // Retrieves window from renderer
    GLFWwindow* window = renderer::getWindow();

    while(!glfwWindowShouldClose(window)) {
        renderer::renderAll();

        processInput(window);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}