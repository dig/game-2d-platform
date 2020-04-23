#ifndef ENTITY_H
#define ENTITY_H

#include "vector.h"
#include "AABB.h"

class World;

class Entity {
    public:
        Entity( World *world, Vector pos, AABB aabb ) {
            m_pos = pos;
            m_world = world;
            m_aabb = aabb;
        };

        virtual void tick() = 0;
        virtual void draw() = 0;

        World* getWorld() {
            return m_world;
        }

        Vector getPosition() {
            return m_pos;
        }

        void setPosition( Vector vector ) {
            m_pos = vector;
        }

        Vector getVelocity() {
            return m_vel;
        }

        void setVelocity( Vector vector ) {
            m_vel = vector;
        }

        virtual AABB getAABB() {
            return m_aabb;
        }

        void setAABB( AABB aabb ) {
            m_aabb = aabb;
        }

    protected:
        Vector m_pos = Vector( 0, 0 );
        Vector m_vel = Vector( 0, 0 );
        AABB m_aabb = AABB( Vector( 0, 0 ), Vector( 0, 0 ) );
        World* m_world;
};

#endif