#include "entity.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player: public Entity {
    public:
        Player(float x, float y) : Entity(x, y) {};
        void onKeyPress(GLFWwindow* window, int key, int scancode, int action, int mods);

    private:
        float m_squareSideLen = 20;
        float m_speed = 5;

        void draw() override;
        void tick() override;
};

#endif
