#ifndef LIVINGENTITY_H
#define LIVINGENTITY_H

#include <iostream>
#include <algorithm>
#include "entity.h"

class LivingEntity: public Entity {
public:
    LivingEntity(Vector position, AABB aabb) : Entity(position, aabb) {};

    bool isOnGround() const {
        return m_isOnGround;
    }

    void tick(double dt) override;

    void position(Vector position) override;

    AABB aabb() override;

protected:
    bool m_isOnGround = false;
};

#endif
