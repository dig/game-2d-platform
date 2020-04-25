#ifndef PLAYER_H
#define PLAYER_H

#include <GLFW/glfw3.h>
#include "window.h"
#include "livingentity.h"

#define PLAYER_SIZE 40

extern Window *g_window;

class Player : public LivingEntity {
public:
    Player(Vector position) : LivingEntity(position, AABB(Vector(position.x(), position.y()), Vector(position.x() + PLAYER_SIZE, position.y() + PLAYER_SIZE))) {};

private:
    float m_squareSideLen = PLAYER_SIZE;

    void draw() override;

    void tick(double dt) override;
};

#endif
