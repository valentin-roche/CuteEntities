#include "Player.h"

Player::Player(QPoint viewSize) : MovingEntity({0, 0}, {19, 30}), m_viewSize(viewSize)
{
    m_position = {100, 100};
    m_sprite.load(":/sprite_mario.png");
    m_numberOfSprite = 3;
    m_animated = true;

}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        m_leftPressed = true;
    } else if (event->key() == Qt::Key_Right){
        m_rightPressed = true;
    }

    if (event->key() == Qt::Key_Up){
        m_upPressed = true;
    }
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        m_leftPressed = false;
    } else if (event->key() == Qt::Key_Right){
        m_rightPressed = false;
    }

    if (event->key() == Qt::Key_Up){
        m_upPressed = false;
    }
}

void Player::delta(qint64 elapsed)
{
    // Calculate velocity
    float velocityX = m_velocity.x();

    if (m_leftPressed && !m_leftTileEntity){
        velocityX -= acceleration;
    } else if (m_rightPressed && !m_rightTileEntity){
        velocityX += acceleration;
    } else {
        // If no movement on x axis, slow down
        if (velocityX > 0) {
            if (velocityX > deceleration) velocityX -= deceleration;
            else velocityX = 0;
        } else if (velocityX < 0){
            if (velocityX < -1 * deceleration) velocityX += deceleration;
            else velocityX = 0;
        }
    }

    // Jump
    if (m_upPressed && m_jumpAvailable){
        m_velocity.setY(-1 * jumpIntancity);
        m_position.setY(m_position.y() - 2);
        m_upPressed = false;
        m_jumpAvailable = false;
        m_jumped = true;
    }

    // Gravity
    if (!m_downTileEntity) {
        m_jumpAvailable = false;
        m_velocity.setY(m_velocity.y() + gravityIntancity);
    } else {
        m_jumpAvailable = true;
    }

    // Enforce maximum velocity
    if (velocityX > maxWalkingVelocity) velocityX = maxWalkingVelocity;
    if (velocityX < -1 * maxWalkingVelocity) velocityX = -1 * maxWalkingVelocity;

    if (m_velocity.y() > maxFallingVelocity) m_velocity.setY(maxFallingVelocity);

    m_velocity.setX(velocityX);

    // Calculate world position
    if (m_position.x() < 0) m_position.setX(0);
    m_position.setX(m_position.x() + m_velocity.x());
    m_position.setY(m_position.y() + m_velocity.y());

    if (m_position.x() < 0) m_position.setX(0);

    // Calculate display position
    int displayXPosition;
    if (m_position.x() < (m_viewSize.x() / 2)) {
        displayXPosition = m_position.x();
    } else {
        displayXPosition = m_viewSize.x() / 2;
    }

    setPos(displayXPosition, m_position.y());

    // Animations
    updateSpriteDirection();

    if (!m_downTileEntity) {
        m_animated = false;
        m_currentSprite = 0;
    } else {
        m_animated = m_velocity.x() != 0;
    }

    if (!m_animated) {
        m_currentSprite = 0;
    }

    updateSprite();
}

bool Player::getJumped()
{
    bool temp = m_jumped;
    m_jumped = false;

    return temp;
}

