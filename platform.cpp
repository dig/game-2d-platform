#include "platform.h"

void Platform::draw()
{
    glBegin(GL_POLYGON);
    glVertex2f(m_pos.getX(), m_pos.getY());
    glVertex2f(m_pos.getX() + m_width, m_pos.getY());
    glVertex2f(m_pos.getX() + m_width, m_pos.getY() + m_height);
    glVertex2f(m_pos.getX(), m_pos.getY() + m_height);
    glEnd();
}

void Platform::tick() {}