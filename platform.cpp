#include "platform.h"

void Platform::draw() {
    glBegin(GL_POLYGON);
    glVertex2f(m_pos.x(), m_pos.y());
    glVertex2f(m_pos.x() + m_width, m_pos.y());
    glVertex2f(m_pos.x() + m_width, m_pos.y() + m_height);
    glVertex2f(m_pos.x(), m_pos.y() + m_height);
    glEnd();
}

void Platform::tick(double dt) {}