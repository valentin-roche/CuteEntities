#include "CollisionHandler.h"

void CollisionHandler::playerTile(Player *player, Tile *tile, int mapOffset)
{
    RectPoints playerPoints = getPoints(player);
    RectPoints tilePoints = getPoints(tile, mapOffset);

    // For both axis get the side the player is comming from
    // And the value of "penetration"
    Directions horizontalSide;
    float horizontalValue;

    if (playerPoints.topRight.x() <= tilePoints.center.x()) {
        horizontalSide = Directions::Left;
        horizontalValue = playerPoints.topRight.x() - tilePoints.topLeft.x();
    } else {
        horizontalSide = Directions::Right;
        horizontalValue = tilePoints.topRight.x() - playerPoints.topLeft.x();
    }
    Directions verticalSide;
    float verticalValue;

    if (playerPoints.bottomRight.y() <= tilePoints.center.y()) {
        verticalSide = Directions::Top;
        verticalValue = playerPoints.bottomRight.y() - tilePoints.topRight.y();
    } else {
        verticalSide = Directions::Bottom;
        verticalValue = tilePoints.bottomRight.y() - playerPoints.topRight.y();
    }

    if (verticalValue < horizontalValue) {
        // Move the player on the vertical axis
        if (verticalSide == Directions::Top) {
            verticalValue *= -1;
        }

        player->correctCollision({0, (int) verticalValue});
    } else {
        // Move the player on the horizontal axis
        if (horizontalSide == Directions::Left) {
            horizontalValue *= -1;
        }

        player->correctCollision({(int) horizontalValue, 0});
    }
}

bool CollisionHandler::playerEnemy(Player *player, Enemy *enemy, int mapOffset, EntityManager* entityManager)
{
    RectPoints playerPoints = getPoints(player);
    RectPoints enemyPoints = getPoints(enemy, mapOffset);

    // For both axis get the side the player is comming from
    // And the value of "penetration"
    Directions horizontalSide;
    float horizontalValue;

    if (playerPoints.topRight.x() <= enemyPoints.center.x()) {
        horizontalSide = Directions::Left;
        horizontalValue = playerPoints.topRight.x() - enemyPoints.topLeft.x();
    } else {
        horizontalSide = Directions::Right;
        horizontalValue = enemyPoints.topRight.x() - playerPoints.topLeft.x();
    }
    Directions verticalSide;
    float verticalValue;

    if (playerPoints.bottomRight.y() <= enemyPoints.center.y()) {
        verticalSide = Directions::Top;
        verticalValue = playerPoints.bottomRight.y() - enemyPoints.topRight.y();
    } else {
        verticalSide = Directions::Bottom;
        verticalValue = enemyPoints.bottomRight.y() - playerPoints.topRight.y();
    }

    if (verticalValue < horizontalValue) {
        entityManager->killEnemy(enemy);
        player->bounce(10);
        return true;

    } else {
        entityManager->killPlayer(player);
        return false;
    }
}

void CollisionHandler::playerCoin(Player *player, Coin *coin, int mapOffset, EntityManager* entityManager)
{
    entityManager->getCoin(coin);
}

CollisionHandler::RectPoints CollisionHandler::getPoints(QGraphicsItem *item, int offset)
{
    RectPoints points;

    QRectF rect = item->boundingRect();

    points.topLeft = {rect.x() + item->pos().x() + offset, rect.y() + item->pos().y()};
    points.topRight = {points.topLeft.x() + rect.width(), points.topLeft.y()};
    points.bottomLeft = {points.topLeft.x(), rect.y() + rect.height()};
    points.bottomRight = {points.topLeft.x() + rect.width(), points.topLeft.y() + rect.height()};
    points.center = {points.topLeft.x() + (rect.width() / 2), points.topLeft.y() + (rect.height() / 2)};

    return points;
}
