#include "Tile.h"

Tile::Tile(QPoint tilePosition, QPointF position, TileSet& tileset) :
    m_tilePosition(tilePosition), m_position(position), m_tileSize(tileset.getTileSize()), m_tileset(tileset)
{
    setPos(position);
}

QRectF Tile::boundingRect() const
{
    return QRectF(0, 0, m_tileSize.x(), m_tileSize.y());
}

QPainterPath Tile::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, m_tileSize.x(), m_tileSize.y());
    return path;
}

void Tile::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget)
{
    if (!isEnabled()) return;

    painter->drawImage(QRectF{0, 0, m_tileSize.x(), m_tileSize.y()}, m_tileset.getImage(), m_tileset.getTileRect(m_descriptorName));
}

bool Tile::hasCollision()
{
    return isEnabled() && m_tileset.hasCollision(m_descriptorName);
}

bool Tile::hasWin()
{
    return isEnabled() && m_tileset.hasWin(m_descriptorName);
}

bool Tile::hasKill()
{
    return isEnabled() && m_tileset.hasKill(m_descriptorName);
}

bool Tile::hasCollapse()
{
    return isEnabled() && m_tileset.hasCollapse(m_descriptorName);
}

bool Tile::hasBounce()
{
    return isEnabled() && m_tileset.hasBounce(m_descriptorName);
}
