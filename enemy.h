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

    void setTileArround(bool leftTile, bool rightTile, bool downTile);

    void delta(qint64 elapsed) override;

    //hitPlayer();

private:
    QPoint m_viewSize;
    int direction = 0;
    int stepDirection = 0;
    bool m_jumpAvailable = false;

};

#endif // ENEMY_H
