#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <GLFW/glfw3.h>

class Window {
    public:
        Window(char* name, int width, int height);

        GLFWwindow* getWindow() {
            return m_window;
        };

        bool hasError() {
            return m_error;
        }

    private:
        GLFWwindow* m_window;
        bool m_error = false;

    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mod);
};

#endif
