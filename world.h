#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>
#include <GLFW/glfw3.h>
#include "entity.h"
#include "platform.h"
#include "player.h"
#include "window.h"

extern Window *g_window;

class World {
private:
    std::vector<Entity *> m_entities;

public:
    World();

    void tick(double dt);

    void draw();

    std::vector<Entity *> entities() {
        return m_entities;
    }

    void addEntity(Entity *entity) {
        m_entities.push_back(entity);
    }
};

#endif