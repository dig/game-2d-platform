#include "player.h"

void Player::draw() {
    glBegin(GL_POLYGON);
    glVertex2f(m_pos.getX(), m_pos.getY());
    glVertex2f(m_pos.getX() + m_squareSideLen, m_pos.getY());
    glVertex2f(m_pos.getX() + m_squareSideLen, m_pos.getY() + m_squareSideLen);
    glVertex2f(m_pos.getX(), m_pos.getY() + m_squareSideLen);
    glEnd();
}

void Player::tick() {
    // controls
    if (glfwGetKey(g_window->getWindow(), GLFW_KEY_D) == GLFW_PRESS) {
        m_pos.add( Vector( m_speed, 0 ) );
    } else if (glfwGetKey(g_window->getWindow(), GLFW_KEY_A) == GLFW_PRESS) {
        m_pos.subtract( Vector( m_speed, 0 ) );
    } else if (glfwGetKey(g_window->getWindow(), GLFW_KEY_SPACE) == GLFW_PRESS) {
        m_pos.subtract( Vector( 0, m_speed ) );
    }

    // temp gravity
    m_pos.add( getVelocity() );
}

AABB Player::getAABB() {
    Vector pos = getPosition();
    return AABB( pos, Vector( pos.getX() + m_squareSideLen, pos.getY() + m_squareSideLen ) );
}