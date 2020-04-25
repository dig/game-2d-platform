#ifndef ENTITY_H
#define ENTITY_H

#include <algorithm>
#include <vector>
#include "vector.h"
#include "AABB.h"

class Entity {
public:
    Entity(Vector pos, AABB aabb) {
        m_pos = pos;
        m_aabb = aabb;
    };

    virtual void tick(double dt) = 0;

    virtual void draw() = 0;

    virtual void collision(Entity *entity) {
        m_collisions.push_back(entity);
    }

    virtual void collisionEnd(Entity *entity) {
        m_collisions.erase(std::remove(m_collisions.begin(), m_collisions.end(), entity), m_collisions.end());
    }

    Vector position() {
        return m_pos;
    }

    virtual void position(Vector vector) {
        m_pos = vector;
    }

    Vector velocity() {
        return m_vel;
    }

    void velocity(Vector vector) {
        m_vel = vector;
    }

    Vector acceleration() {
        return m_acc;
    }

    void acceleration(Vector vector) {
        m_acc = vector;
    }

    virtual AABB aabb() {
        return m_aabb;
    }

    void aabb(AABB aabb) {
        m_aabb = aabb;
    }

    std::vector<Entity *> &collisions() {
        return m_collisions;
    }

protected:
    Vector m_pos = Vector(0, 0);
    Vector m_vel = Vector(0, 0);
    Vector m_acc = Vector(0, -140.8);
    AABB m_aabb = AABB(Vector(0, 0), Vector(0, 0));
    std::vector<Entity *> m_collisions;
};

#endif