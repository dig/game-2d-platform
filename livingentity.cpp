#include "livingentity.h"

void LivingEntity::position(Vector position) {
    // check if we can move to new position
    bool moveTo = true;

    AABB aabbTo = AABB(position, Vector(position.x() + aabb().deltaX(), position.y() + aabb().deltaY()));
    for (Entity *ent : m_collisions) {
        if (ent->aabb().collides(aabbTo, -1)) {
            moveTo = false;
        }
    }

    if (moveTo) {
        m_pos = position;
    }
}

void LivingEntity::tick(double dt) {
    // isOnGround
    m_isOnGround = false;
    AABB translated = aabb().translate(Vector(0, 1));
    for (Entity *ent : m_collisions) {
        if (ent->aabb().collides(translated)) {
            m_isOnGround = true;
            break;
        }
    }

    // gravity
    if (!m_isOnGround) {
        Vector velo = velocity();
        velo.add(Vector(0, dt * acceleration().y()));
        velocity(velo);
    } else {
        if (m_vel.y() < 0) {
            m_vel = Vector(m_vel.x(), 0);
        }
    }

    // velocity
    Vector to = Entity::position();
    to.subtract(Vector(dt * velocity().x(), dt * velocity().y()));
    position(to);

    // acceleration
    // velocity(Vector(velocity().x() + (dt * acceleration().x()), velocity().y() + (dt * acceleration().y())));

    std::cout << "m_isOnGround: " << m_isOnGround << " " << "x:" << velocity().x() << " y:" << velocity().y() << std::endl;
}

AABB LivingEntity::aabb() {
    Vector pos = Entity::position();
    return {pos,Vector(pos.x() + m_aabb.deltaX(), pos.y() + m_aabb.deltaY())};
}