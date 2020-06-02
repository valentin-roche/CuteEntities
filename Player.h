#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QPointF>
#include <QDebug>
#include <QPainter>

#include "MovingEntity.h"
#include <QGraphicsRectItem>

class Player : public MovingEntity {

public:
    Player(QPoint viewSize);
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

    void setTileArround(bool leftTile, bool rightTile, bool downTile);

    void delta(qint64 elapsed) override;

private:
    QPoint m_viewSize;

    bool m_leftTile = false;
    bool m_rightTile = false;
    bool m_downTile = false;

    bool m_jumpAvailable = false;

    bool m_leftPressed = false;
    bool m_rightPressed = false;
    bool m_upPressed = false;
};

#endif // PLAYER_H