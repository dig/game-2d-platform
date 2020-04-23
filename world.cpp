#include "world.h"

World::World() {
    // setup world
}

void World::tick() {
    // tick world here

    // tick entities
    for (Entity* ent : entities) {
        ent->tick();
    }

    // collision detection
    for (Entity* ent1 : entities) {
        for (Entity* ent2 : entities) {
            // check if ent1 collides with ent2
            bool collides = ent1->getAABB().collides( ent2->getAABB() );

            if (collides) {
                std::cout << "collision: " << collides << std::endl;
                ent1->setVelocity( Vector(0, 0) );
                ent2->setVelocity( Vector(0, 0) );
            }
        }
    }
}

void World::draw() {
    // draw world here

    // draw entities
    for (Entity* ent : entities) {
        ent->draw();
    }
}

std::vector<Entity*> World::getEntities() {
    return entities;
};

void World::addEntity(Entity* entity) {
    entities.push_back(entity);
}