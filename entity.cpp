#include "entity.h"

Entity::Entity(QPointF position, int x_size, int y_size) : m_position(position), m_y_size(y_size), m_x_size(x_size)
{
}

QRectF Entity::boundingRect() const
{
    return QRectF(0, 0, m_x_size, m_y_size);
}

QPainterPath Entity::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, m_x_size, m_y_size);
    return path;
}

void Entity::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget)
{
    if (!isEnabled()) return;

    painter->drawRect(m_position.x(), m_position.y(), m_x_size, m_y_size);
}

void Entity::delta(qint64 elapsed)
{

    qDebug() << "elapsed since last call : " << elapsed - m_lastCall;
    m_lastCall = elapsed;
}
