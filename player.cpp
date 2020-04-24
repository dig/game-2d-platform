#include "player.h"

AABB Player::aabb() {
    Vector pos = position();
    return {pos, Vector(pos.x() + m_squareSideLen, pos.y() + m_squareSideLen)};
}

void Player::draw() {
    glBegin(GL_POLYGON);
    glVertex2f(m_pos.x(), m_pos.y());
    glVertex2f(m_pos.x() + m_squareSideLen, m_pos.y());
    glVertex2f(m_pos.x() + m_squareSideLen, m_pos.y() + m_squareSideLen);
    glVertex2f(m_pos.x(), m_pos.y() + m_squareSideLen);
    glEnd();
}

void Player::tick(double dt) {
    // todo: isOnGround

    // controls
    Vector to = position();
    if (glfwGetKey(g_window->getWindow(), GLFW_KEY_D) == GLFW_PRESS) {
        to.add(Vector(m_speed, 0));
    }
    if (glfwGetKey(g_window->getWindow(), GLFW_KEY_A) == GLFW_PRESS) {
        to.subtract(Vector(m_speed, 0));
    }
    if (glfwGetKey(g_window->getWindow(), GLFW_KEY_W) == GLFW_PRESS) {
        to.subtract(Vector(0, m_speed));
    }
    if (!m_isOnGround && glfwGetKey(g_window->getWindow(), GLFW_KEY_S) == GLFW_PRESS) {
        to.add(Vector(0, m_speed));
    }

    // only move if position has been changed
    if (!m_pos.equals(to)) {
        // check if we can move
        bool moveTo = true;

        AABB aabbTo = AABB(to, Vector(to.x() + m_squareSideLen, to.y() + m_squareSideLen));
        for (Entity *ent : m_collisions) {
            if (ent->aabb().collides(aabbTo, -0.15)) {
                moveTo = false;
            }
        }

        if (moveTo) {
            m_pos = to;
        }
    }

    // todo: gravity
    m_pos.add(Vector(0, dt * 9.8));
}