#include "world.h"

void World::tick() {
    // tick world here

    // tick entities
    for (Entity* ent : entities) {
        ent->tick();
    }
}

void World::draw() {
    // draw world here

    // draw entities
    for (Entity* ent : entities) {
        ent->draw();
    }
}

vector<Entity*> World::getEntities() {
    return entities;
};

void World::addEntity(Entity* entity) {
    entities.push_back(entity);
}