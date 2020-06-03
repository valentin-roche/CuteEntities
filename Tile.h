#ifndef TILE_H
#define TILE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPointF>

#include "TileSet.h"

class Tile : public QGraphicsItem
{
public:
    Tile(QPoint tilePosition, QPointF position, TileSet& tileset);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

    QPoint getTilePosition() { return m_tilePosition; }

    void enable() { m_enabled = true; };
    void enable(QString descriptorName) {
        enable();
        m_descriptorName = descriptorName;
    }
    void disable() { m_enabled = false; }
    bool isEnabled() { return m_enabled && m_descriptorName.length() > 0; }

    bool hasCollision();
    bool hasWin();
    bool hasKill();
    bool hasCollapse();
    bool hasBounce();

    enum { Type = UserType + 1 };
    int type() const override { return Type; }

private:
    QPoint m_tilePosition;
    QPointF m_position;
    QPointF m_tileSize;
    TileSet& m_tileset;

    QString m_descriptorName = "";

    bool m_enabled = false;
};

#endif // TILE_H
