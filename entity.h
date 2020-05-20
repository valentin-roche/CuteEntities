#ifndef ENTITY_H
#define ENTITY_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

class Entity : public QGraphicsRectItem
{
public:
    Entity(QPointF position, int x_size, int y_size);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

private:
    QPointF m_position;
    int m_y_size, m_x_size;
};

#endif // ENTITY_H
