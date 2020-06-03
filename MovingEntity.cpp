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

bool MovingEntity::downTileEntity() const
{
    return m_downTileEntity;
}

void MovingEntity::setDownTileEntity(bool downTileEntity)
{
    m_downTileEntity = downTileEntity;
}

bool MovingEntity::rightTileEntity() const
{
    return m_rightTileEntity;
}

void MovingEntity::setRightTileEntity(bool rightTileEntity)
{
    m_rightTileEntity = rightTileEntity;
}

bool MovingEntity::leftTileEntity() const
{
    return m_leftTileEntity;
}

void MovingEntity::setLeftTileEntity(bool leftTileEntity)
{
    m_leftTileEntity = leftTileEntity;
}

