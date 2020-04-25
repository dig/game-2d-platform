#include "player.h"

void Player::draw() {
    glBegin(GL_POLYGON);
    glVertex2f(m_pos.x(), m_pos.y());
    glVertex2f(m_pos.x() + m_squareSideLen, m_pos.y());
    glVertex2f(m_pos.x() + m_squareSideLen, m_pos.y() + m_squareSideLen);
    glVertex2f(m_pos.x(), m_pos.y() + m_squareSideLen);
    glEnd();
}

void Player::tick(double dt) {
    LivingEntity::tick(dt);

    // controls
    Vector to = Entity::position();
    if (glfwGetKey(g_window->getWindow(), GLFW_KEY_D) == GLFW_PRESS) {
        to.add(Vector(1, 0));
    }
    if (glfwGetKey(g_window->getWindow(), GLFW_KEY_A) == GLFW_PRESS) {
        to.subtract(Vector(1, 0));
    }
    if (m_isOnGround && glfwGetKey(g_window->getWindow(), GLFW_KEY_SPACE) == GLFW_PRESS) {
        velocity(Vector(0, 70));
    }

    // only move if position has been changed
    if (!m_pos.equals(to)) {
        position(to);
    }
}