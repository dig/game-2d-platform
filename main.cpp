#include <iostream>
#include <GLFW/glfw3.h>

#include "world.h"
#include "platform.h"
#include "player.h"
#include "window.h"

Window* g_window;
World* g_world;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mod) {
    for (Entity* ent : g_world->getEntities()) {
        if(Player* player = dynamic_cast<Player*>(ent)) {
            player->onKeyPress(window, key, scancode, action, mod);
        }
    }
}

int main()
{
    g_window = new Window("2D Platform", 640, 480);
    if (g_window->hasError()) return -1;

    g_world = new World();

    int width, height;
    glfwGetFramebufferSize(g_window->getWindow(), &width, &height);

    Platform floor(0, height - (height / 6), width, height / 6);
    g_world->addEntity(&floor);

    Platform floor1(0, height - (height / 2), width / 3, height / 10);
    g_world->addEntity(&floor1);

    Platform floor2(width - (width / 3), height - (height / 2), width / 3, height / 10);
    g_world->addEntity(&floor2);

    Player player(0, 0);
    g_world->addEntity(&player);

    glfwSetKeyCallback(g_window->getWindow(), keyCallback);

    while (!glfwWindowShouldClose(g_window->getWindow()))
    {
        int width, height;
        glfwGetFramebufferSize(g_window->getWindow(), &width, &height);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0f, width, height, 0.0f, 0.0f, 1.0f);

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        g_world->tick();
        g_world->draw();

        glfwSwapBuffers(g_window->getWindow());
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
