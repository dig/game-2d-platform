#include <iostream>
#include <GLFW/glfw3.h>

#include "world.h"

Window *g_window;
World *g_world;

int main() {
    g_window = new Window("2D Platform", 640, 480);
    if (g_window->hasError()) return -1;

    g_world = new World();

    int width, height;
    glfwGetFramebufferSize(g_window->getWindow(), &width, &height);

    Platform floor(Vector(0, height - (height / 6)), width, height / 6);
    g_world->addEntity(&floor);

    Platform floor1(Vector(0, height - (height / 2)), width / 3, height / 10);
    g_world->addEntity(&floor1);

    Platform floor2(Vector(width - (width / 3), height - (height / 2)), width / 3, height / 10);
    g_world->addEntity(&floor2);

    Player player(Vector(0, 0));
    g_world->addEntity(&player);


    double t = 0.0;
    double dt = 1.0 / 60.0;

    while (!glfwWindowShouldClose(g_window->getWindow())) {
        int width, height;
        glfwGetFramebufferSize(g_window->getWindow(), &width, &height);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0f, width, height, 0.0f, 0.0f, 1.0f);

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        g_world->tick(dt);
        g_world->draw();

        glfwSwapBuffers(g_window->getWindow());
        glfwPollEvents();

        t += dt;
    }

    glfwTerminate();
    return 0;
}
