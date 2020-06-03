#include "enemy.h"

Enemy::Enemy(QPoint position, QPoint viewSize) : MovingEntity(position, {10, 10})
{
     m_position.setX(position.x());
     m_position.setY(position.y());
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget)
{
    painter->fillRect(QRectF{0, 0, 10, 10}, Qt::black);
}

void Enemy::setTileArround(bool leftTile, bool rightTile, bool downTile)
{
    m_leftTileEntity = leftTile;
    m_rightTileEntity = rightTile;
    m_downTileEntity = downTile;
}

void Enemy::delta(qint64 elapsed)
{
    int newDirection = BasicAI::predictNextMove(stepDirection, direction, false, 0);

    // Calculate velocity
    float velocityX = m_velocity.x();


    if (direction != newDirection){
        stepDirection = 0;
        qDebug() << "direction" << direction;
        qDebug() << "newDirection" << newDirection;
        velocityX = newDirection;
        m_velocity.setX(velocityX);
        qDebug() << "velocity" << velocityX;
        direction = newDirection;
    }

    // Gravity
    if (!m_downTileEntity) {
        m_velocity.setY(m_velocity.y() + 1);
    }
    else {
        m_velocity.setY(0);
    }

    // Enforce maximum velocity
    if (velocityX > 0.5) velocityX = 0.5;
    if (velocityX < -0.5) velocityX = -0.5;
    //qDebug() << velocityX;

    if (m_velocity.y() > 3) m_velocity.setY(3);

    m_position.setX(m_position.x() + m_velocity.x());
    m_position.setY(m_position.y() + m_velocity.y());

    // Calculate display position
    setPos(m_position.x() + m_tilemapOffset, m_position.y());
    stepDirection++;


}
