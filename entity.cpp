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

void Entity::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget)
{
    if (!m_sprite.isNull()) {
        painter->drawImage(QRectF{ 0, 0, (float) m_size.x(), (float) m_size.y() },
                           m_sprite,
                           QRectF{(float) m_currentSprite * m_size.x(), (float) m_spriteLine * m_size.y(), (float) m_size.x(), (float) m_size.y() });
    }
}
