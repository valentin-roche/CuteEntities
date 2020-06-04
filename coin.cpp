#include "coin.h"

Coin::Coin(QPoint position, QPoint viewSize) : Entity(position, {10, 10}) {}
void Coin::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget)
{
    painter->fillRect(QRectF{0, 0, 10, 10}, Qt::yellow);
}

void Coin::delta(qint64 elapsed) {
    setPos(m_position.x() + m_tilemapOffset, m_position.y());
}
