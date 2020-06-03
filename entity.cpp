#include "entity.h"

Entity::Entity(QPoint position, QPoint size) : m_position(position), m_size(size)
{
}

QRectF Entity::boundingRect() const
{
    return QRectF(0, 0, m_size.x(), m_size.y());
}

QPainterPath Entity::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, m_size.x(), m_size.y());
    return path;
}
