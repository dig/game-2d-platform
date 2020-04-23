#ifndef PLAYER_H
#define PLAYER_H

#include <GLFW/glfw3.h>
#include "entity.h"
#include "window.h"

extern Window* g_window;

class Player: public Entity {
    public:
        Player( World* world, Vector position ) : Entity( world, position, AABB( Vector( 0, 0 ), Vector( 0, 0 ) ) ) {};

    private:
        float m_squareSideLen = 20;
        float m_speed = 2;

        void draw() override;
        void tick() override;

        AABB getAABB() override;
};

#endif
