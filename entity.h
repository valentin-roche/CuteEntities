#ifndef ENTITY_H
#define ENTITY_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QStaticText>
#include <QDebug>
#include <QPointF>
#include <QElapsedTimer>

class Entity : public QGraphicsItem
{

public:
    Entity(QPoint position, QPoint size);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
    virtual void delta(qint64 elapsed) = 0;

    QPoint getPosition() { return m_position; }
    void setPosition(QPoint newPos) { m_position = newPos; }

    void setTileMapOffset(int offset) { m_tilemapOffset = offset; }
    bool getIsMoving() { return isMoving; }

protected:
    QPoint m_position;
    QPoint m_size;
    QImage m_sprite;

    int m_spriteLine = 0;
    int m_currentSprite = 0;
    bool m_animated = false;
    int m_numberOfSprite = 0;
    QElapsedTimer m_animationTimer;

    bool isMoving = false;

    int m_tilemapOffset = 0;

private:
    qint64 m_lastCall = 0;

};

#endif // ENTITY_H
