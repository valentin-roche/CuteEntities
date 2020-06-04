#include "enemy.h"

Enemy::Enemy(QPoint position, QPoint viewSize) : MovingEntity(position, {17, 18})
{
     m_position.setX(position.x());
     m_position.setY(position.y());

     m_sprite.load(":/sprite_boomba.png");
     m_numberOfSprite = 3;
     m_animated = true;
}

void Enemy::delta(qint64 elapsed)
{
    int newDirection = BasicAI::predictNextMove(stepDirection, direction, false, 0);

    // Calculate velocity
    float velocityX = m_velocity.x();


    if (direction != newDirection){
        stepDirection = 0;
        velocityX = newDirection;
        m_velocity.setX(velocityX);
        direction = newDirection;
    }

    // Gravity
    if (!m_downTileEntity) {
        m_velocity.setY(m_velocity.y() + gravityIntancity);
    }
    else {
        m_velocity.setY(0);
    }

    // Enforce maximum velocity
    if (velocityX > 0.5) velocityX = 0.5;
    if (velocityX < -0.5) velocityX = -0.5;

    if (m_velocity.y() > maxFallingVelocity) m_velocity.setY(maxFallingVelocity);

    m_position.setX(m_position.x() + m_velocity.x());
    m_position.setY(m_position.y() + m_velocity.y());

    // Calculate display position
    setPos(m_position.x() + m_tilemapOffset, m_position.y());
    stepDirection++;

    updateSpriteDirection();
    updateSprite();
}

