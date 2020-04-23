#include <vector>
#include <GLFW/glfw3.h>
#include "entity.h"
#include "platform.h"
#include "player.h"
#include "window.h"

#ifndef WORLD_H
#define WORLD_H

extern Window* g_window;
using namespace std;

class World {
    private:
        vector<Entity*> entities;

    public:
        World();

        void tick();
        void draw();

        vector<Entity*> getEntities();
        void addEntity(Entity* entity);
};

#endif