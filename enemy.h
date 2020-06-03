#ifndef ENEMY_H
#define ENEMY_H
#include <MovingEntity.h>
#include <QGraphicsRectItem>
#include "basicai.h"
class Enemy : public MovingEntity
{
public:
    Enemy(QPoint position, QPoint viewSize);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

    void delta(qint64 elapsed) override;

    //hitPlayer();
    enum { Type = UserType + 10 };
    int type() const override { return Type; }
private:
    QPoint m_viewSize;
    int direction = BasicAI::RIGHT;
    int stepDirection = 0;
    bool m_jumpAvailable = false;

};

#endif // ENEMY_H
