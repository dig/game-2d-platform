#include <iostream>
#include <GLFW/glfw3.h>
#include <math.h>

#include "world.h"
#include "platform.h"
#include "player.h"

World g_world = World();

void onKeyPress(GLFWwindow* window, int key, int scancode, int action, int mod) {
    for (Entity* ent : g_world.getEntities()) {
        if(Player* player = dynamic_cast<Player*>(ent)) {
            player->onKeyPress(window, key, scancode, action, mod);
        }
    }
}

int main()
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(640, 480, "2D Platform", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    Platform floor(0, height - (height / 6), width, height / 6);
    g_world.addEntity(&floor);

    Platform floor1(0, height - (height / 2), width / 3, height / 10);
    g_world.addEntity(&floor1);

    Platform floor2(width - (width / 3), height - (height / 2), width / 3, height / 10);
    g_world.addEntity(&floor2);

    Player player(window, 0, 0);
    g_world.addEntity(&player);

    glfwSetKeyCallback(window, onKeyPress);

    while (!glfwWindowShouldClose(window))
    {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0f, width, height, 0.0f, 0.0f, 1.0f);

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        g_world.tick();
        g_world.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
