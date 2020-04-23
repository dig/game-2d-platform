#ifndef AABB_H
#define AABB_H

#include "vector.h"

class AABB {
    public:
        AABB( Vector min, Vector max ) {
            m_min = min;
            m_max = max;
        }

        Vector getMin() {
            return m_min;
        }

        Vector getMax() {
            return m_max;
        }

    /*
    float d1x = b->min.x - a->max.x;
    float d1y = b->min.y - a->max.y;
    float d2x = a->min.x - b->max.x;
    float d2y = a->min.y - b->max.y; */

        bool collides( AABB with ) {
            float d1x = with.getMin().getX() - m_max.getX();
            float d1y = with.getMin().getY() - m_max.getY();
            float d2x = m_min.getX() - with.getMax().getX();
            float d2y = m_min.getY() - with.getMax().getY();

            if ( d1x > 0.0f || d1y > 0.0f ) {
                return false;
            }

            if ( d2x > 0.0f || d2y > 0.0f ) {
                return false;
            }

            return true;
        }

    private:
        Vector m_min = Vector( 0, 0 );
        Vector m_max = Vector( 0, 0 );
};

#endif
