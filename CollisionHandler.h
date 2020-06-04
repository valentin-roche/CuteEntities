#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include <QRectF>
#include <QPointF>
#include <QGraphicsItem>

#include "Player.h"
#include "enemy.h"
#include "Tile.h"
#include "entitymanager.h"


class CollisionHandler {

public:
    static void playerTile(Player* player, Tile* tile, int mapOffset);
    static void playerEnemy(Player *player, Enemy *enemy, int mapOffset, EntityManager* entityManager);
    static void playerCoin(Player *player, Coin *coin, int mapOffset, EntityManager* entityManager);
private:
    struct RectPoints {
        QPointF topLeft;
        QPointF topRight;
        QPointF bottomLeft;
        QPointF bottomRight;
        QPointF center;
    };

    enum Directions {
        Left, Right,
        Bottom, Top
    };
signals:
    void gameOver(const QString& text) const;

private:
    static RectPoints getPoints(QGraphicsItem *item, int offset = 0);
};

#endif // COLLISIONHANDLER_H
