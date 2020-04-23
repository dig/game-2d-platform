#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>
#include <GLFW/glfw3.h>
#include "entity.h"
#include "platform.h"
#include "player.h"
#include "window.h"

extern Window* g_window;

class World {
    private:
        std::vector<Entity*> entities;

    public:
        World();

        void tick();
        void draw();

        std::vector<Entity*> getEntities();
        void addEntity( Entity* entity );
};

#endif