#ifndef PLATFORM_H
#define PLATFORM_H

#include <iostream>
#include <GLFW/glfw3.h>
#include "entity.h"

class Platform : public Entity {
public:
    Platform(Vector position, float width, float height)
            : Entity(position, AABB(position, Vector(position.x() + width, position.y() + height))) {

        m_width = width;
        m_height = height;
    };

    void tick(double dt) override;

    void draw() override;

private:
    float m_width, m_height;
};

#endif