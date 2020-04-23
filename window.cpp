#include "window.h"

Window::Window(char* name, int width, int height) {
    if (!glfwInit()) {
        m_error = true;
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    m_window = glfwCreateWindow(width, height, name, NULL, NULL);
    if (!m_window) {
        glfwTerminate();
        m_error = true;
        return;
    }

    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(1);
}