#include "world.h"
#include <algorithm>

World::World() {
    // setup world
}

void World::tick(double dt) {
    // tick entities
    for (Entity *ent : m_entities) {
        ent->tick(dt);
    }

    // collision detection
    for (Entity *ent1 : m_entities) {
        for (Entity *ent2 : m_entities) {
            if (ent1 == ent2) {
                continue;
            }

            bool colliding = ent1->aabb().collides(ent2->aabb(), 5);
            bool collidedAlready = std::find(ent1->collisions().begin(), ent1->collisions().end(), ent2)
                                      != ent1->collisions().end();
            if (!colliding && collidedAlready) {
                ent1->collisionEnd(ent2);
            } else if (colliding && !collidedAlready) {
                ent1->collision(ent2);
            }
        }
    }
}

void World::draw() {
    // draw entities
    for (Entity *ent : m_entities) {
        ent->draw();
    }
}