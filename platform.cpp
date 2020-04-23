#include <iostream>
#include <GLFW/glfw3.h>
#include "platform.h"

void Platform::draw()
{
    glBegin(GL_POLYGON);
    glVertex2f(m_posx, m_posy);
    glVertex2f(m_posx + m_width, m_posy);
    glVertex2f(m_posx + m_width, m_posy + m_height);
    glVertex2f(m_posx, m_posy + m_height);
    glEnd();
}

void Platform::tick()
{
    // std::cout << "tick()" << std::endl;
}