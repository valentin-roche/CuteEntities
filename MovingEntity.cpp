#include "MovingEntity.h"

MovingEntity::MovingEntity(QPoint position, QPoint size)
    : Entity(position, size)
{}

void MovingEntity::correctCollision(QPoint correction)
{
    if (correction.x() != 0) {
        m_velocity.setX(0);
        m_position.setX(m_position.x() + correction.x());
    }

    if (correction.y() != 0) {
        m_velocity.setY(0);
        m_position.setY(m_position.y() + correction.y());
    }
}

void MovingEntity::bounce(int intensity)
{
    m_velocity.setY(m_velocity.y() - intensity);
    m_position.setY(m_position.y() - 2);
}
