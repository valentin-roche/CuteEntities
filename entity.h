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
    Entity(QPoint position, int x_size, int y_size);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
    void delta(qint64 elapsed);

protected:
    QPoint m_position;

private:
    int m_y_size, m_x_size;
    QString m_descriptorName = "";
    qint64 m_lastCall = 0;
};

#endif // ENTITY_H
