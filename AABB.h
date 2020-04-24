#ifndef AABB_H
#define AABB_H

#include "vector.h"

class AABB {
public:
    AABB(Vector min, Vector max) {
        m_min = min;
        m_max = max;
    }

    Vector min() {
        return m_min;
    }

    Vector max() {
        return m_max;
    }

    bool collides(AABB with, float padding = 0) {
        float d1x = (with.min().x() - padding) - (m_max.x() + padding);
        float d1y = (with.min().y() - padding) - (m_max.y() + padding);
        float d2x = (m_min.x() - padding) - (with.max().x() + padding);
        float d2y = (m_min.y() - padding) - (with.max().y() + padding);

        if (d1x > 0.0f || d1y > 0.0f) {
            return false;
        }
        if (d2x > 0.0f || d2y > 0.0f) {
            return false;
        }
        return true;
    }

private:
    Vector m_min = Vector(0, 0);
    Vector m_max = Vector(0, 0);
};

#endif
