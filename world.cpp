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
        if (collidesWithEntity(ent1)) {
            ent1->setVelocity( Vector(0, 0) );
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

void World::addEntity( Entity* entity ) {
    entities.push_back( entity );
}

bool World::collidesWithEntity( Entity* entity, Vector aabb ) {
    bool result = false;

    for ( Entity* ent2 : entities ) {
        if ( entity == ent2 ) continue;

        if ( aabb.collides( ent2->getAABB() ) ) {
            result = true;
        }
    }

    return result;
}