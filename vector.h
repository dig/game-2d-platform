#ifndef VECTOR_H
#define VECTOR_H

class Vector {
public:
    Vector(float x, float y) {
        m_x = x;
        m_y = y;
    }

    float x() {
        return m_x;
    }

    float y() {
        return m_y;
    }

    void add(Vector position) {
        m_x += position.x();
        m_y += position.y();
    }

    void subtract(Vector position) {
        m_x -= position.x();
        m_y -= position.y();
    }

    void multiply(float x) {
        m_x *= x;
        m_y *= x;
    }

    bool equals(Vector x) {
        return m_x == x.x() && m_y == x.y();
    }

private:
    float m_x, m_y;
};

#endif
