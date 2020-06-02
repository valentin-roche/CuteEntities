#include "Player.h"

Player::Player(QPoint viewSize) : MovingEntity({0, 0}, {20, 30}), m_viewSize(viewSize)
{
    m_position = {100, 100};
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

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget)
{
    painter->fillRect(QRectF{0, 0, 20, 30}, Qt::red);
}

void Player::setTileArround(bool leftTile, bool rightTile, bool downTile)
{
    m_leftTile = leftTile;
    m_rightTile = rightTile;
    m_downTile = downTile;
}

void Player::delta(qint64 elapsed)
{
    // Calculate velocity
    float velocityX = m_velocity.x();

    if (m_leftPressed && !m_leftTile){
        if (velocityX == 0) velocityX -= 0.5;
        velocityX -= 1;
    } else if (m_rightPressed && !m_rightTile){
        if (velocityX == 0) velocityX += 0.5;
        velocityX += 1;
    } else {
        // If no movement on x axis, slow down
        if (velocityX > 0) {
            if (velocityX > 0.1) velocityX -= 0.1;
            else velocityX = 0;
        } else if (velocityX < 0){
            if (velocityX < -0.1) velocityX += 0.1;
            else velocityX = 0;
        }
    }

    // Jump
    if (m_upPressed && m_jumpAvailable){
        m_velocity.setY(-10);
        m_position.setY(m_position.y() - 2);
        m_upPressed = false;
        m_jumpAvailable = false;
    }

    // Gravity
    if (!m_downTile) {
        m_jumpAvailable = false;
        m_velocity.setY(m_velocity.y() + 1);
    } else {
        m_jumpAvailable = true;
    }

    // Enforce maximum velocity
    if (velocityX > 3) velocityX = 3;
    if (velocityX < -3) velocityX = -3;

    if (m_velocity.y() > 3) m_velocity.setY(3);

    m_velocity.setX(velocityX);

    // Calculate world position
    m_position.setX(m_position.x() + m_velocity.x());
    m_position.setY(m_position.y() + m_velocity.y());

    // Calculate display position
    int displayXPosition;
    if (m_position.x() < (m_viewSize.x() / 2)) {
        displayXPosition = m_position.x();
    } else {
        displayXPosition = m_viewSize.x() / 2;
    }

    setPos(displayXPosition, m_position.y());
}
