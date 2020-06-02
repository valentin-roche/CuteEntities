#ifndef ENTITY_H
#define ENTITY_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QStaticText>
#include <QDebug>

class Entity : public QGraphicsItem
{
public:
    Entity(QPoint position, QPoint size);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    virtual void delta(qint64 elapsed) = 0;

    QPoint getPosition() { return m_position; }

protected:
    QPoint m_position;
    QPoint m_size;

private:
    qint64 m_lastCall = 0;
};

#endif // ENTITY_H
