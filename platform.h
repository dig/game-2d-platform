#include "entity.h"

#ifndef PLATFORM_H
#define PLATFORM_H

class Platform: public Entity {
    public:
        Platform(float x, float y, float width, float height) : Entity(x, y) {
            m_width = width;
            m_height = height;
        };

        void tick() override;
        void draw() override;

    private:
        float m_width, m_height;
};

#endif