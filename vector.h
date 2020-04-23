#ifndef VECTOR_H
#define VECTOR_H

class Vector {
    public:
        Vector(float x, float y) {
            m_x = x;
            m_y = y;
        }

        float getX() {
            return m_x;
        }

        float getY() {
            return m_y;
        }

        void add(Vector position) {
            m_x += position.getX();
            m_y += position.getY();
        }

        void subtract(Vector position) {
            m_x -= position.getX();
            m_y -= position.getY();
        }

        void multiply(float x) {
            m_x *= x;
            m_y *= x;
        }

    private:
        float m_x, m_y;
};

#endif
