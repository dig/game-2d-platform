#include <GLFW/glfw3.h>
#include "player.h"

void Player::onKeyPress(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_D && action == GLFW_PRESS) {
        m_posx += m_speed;
    } else if (key == GLFW_KEY_A && action == GLFW_PRESS) {
        m_posx -= m_speed;
    }
}

void Player::draw() {
    glBegin(GL_POLYGON);
    glVertex2f(m_posx, m_posy);
    glVertex2f(m_posx + m_squareSideLen, m_posy);
    glVertex2f(m_posx + m_squareSideLen, m_posy + m_squareSideLen);
    glVertex2f(m_posx, m_posy + m_squareSideLen);
    glEnd();
}

void Player::tick() {
    m_posy += 1;
}