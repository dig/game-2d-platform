#ifndef ENTITY_H
#define ENTITY_H

class Entity {
    public:
        Entity(float x, float y) {
            m_posx = x;
            m_posy = y;
        };

        virtual void tick() = 0;
        virtual void draw() = 0;

    protected:
        float m_posx, m_posy;
};

#endif