#ifndef PLATFORM_H
#define PLATFORM_H

#include <iostream>
#include <GLFW/glfw3.h>
#include "entity.h"

class Platform: public Entity {
    public:
        Platform( World* world, Vector position, float width, float height )
            : Entity( world, position, AABB( position, Vector( position.getX() + width, position.getY() + height ) ) ) {

            m_width = width;
            m_height = height;
        };

        void tick() override;
        void draw() override;

    private:
        float m_width, m_height;
};

#endif