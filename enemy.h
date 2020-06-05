#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>

#include <MovingEntity.h>
#include "basicai.h"

class Enemy : public MovingEntity
{
public:
    Enemy(QPoint position, QPoint viewSize);
    void delta(qint64 elapsed) override;

    enum { Type = UserType + 10 };
    int type() const override { return Type; }

private:
    QPoint m_viewSize;
    int direction = BasicAI::RIGHT;
    int stepDirection = 0;
    bool m_jumpAvailable = false;

};

#endif // ENEMY_H
