#include <vector>
#include "entity.h"

#ifndef WORLD_H
#define WORLD_H

using namespace std;

class World {
    private:
        vector<Entity*> entities;

    public:
        void tick();
        void draw();

        vector<Entity*> getEntities();
        void addEntity(Entity* entity);
};

#endif