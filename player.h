#ifndef PLAYER_H
#define PLAYER_H

#include <GLFW/glfw3.h>
#include "window.h"
#include "entity.h"

extern Window *g_window;

class Player : public Entity {
public:
    Player(Vector position) : Entity(position, AABB(Vector(0, 0), Vector(0, 0))) {};

private:
    float m_squareSideLen = 20;
    float m_speed = 2;
    float m_isOnGround = false;

    void draw() override;

    void tick(double dt) override;

    AABB aabb() override;

    void handleMovement();
};

#endif
