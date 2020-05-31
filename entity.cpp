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

    painter->drawRect(0, 0, m_x_size, m_y_size);
    painter->fillRect(0, 0, m_x_size, m_y_size, Qt::green);
}

void Entity::delta(qint64 elapsed)
{
    m_position.setX(m_position.x()+10);
    setPos(m_position);
    qDebug() << "elapsed since last call : " << elapsed - m_lastCall;
    m_lastCall = elapsed;

}
