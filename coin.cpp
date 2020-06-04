#include "coin.h"

Coin::Coin(QPoint position, QPoint viewSize) : Entity(position, {16, 16})
{
    m_sprite.load(":/sprite_coin.png");
}

void Coin::delta(qint64 elapsed) {
    setPos(m_position.x() + m_tilemapOffset, m_position.y());
}
