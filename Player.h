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

    void delta(qint64 elapsed) override;
    bool getJumped();

private:
    QPoint m_viewSize;

    static constexpr int maxWalkingVelocity = 3;
    static constexpr float acceleration = 1;
    static constexpr float deceleration = 0.3;
    static constexpr int jumpIntancity = 10;

    bool m_jumpAvailable = false;

    bool m_leftPressed = false;
    bool m_rightPressed = false;
    bool m_upPressed = false;

    bool m_jumped = false;
};

#endif // PLAYER_H
