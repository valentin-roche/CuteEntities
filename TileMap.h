#ifndef TILEMAP_H
#define TILEMAP_H

#include <QVector>
#include <QGraphicsItemGroup>
#include <QDebug>

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "TileSet.h"
#include "Tile.h"

class TileMap : public QGraphicsItemGroup {

public:
    TileMap(TileSet* tileset);
    TileMap(TileSet* tileset, QJsonObject size, QJsonArray tiles);

    void loadMap(QJsonObject size, QJsonArray tiles);

    void enableTile(QPointF position);
    void enableTile(QPointF position, QString descriptorName);
    void disableTile(QPointF position);
    void disableAll();

    bool tileExists(QPointF position) const;
    QPointF getTileSize() const {return m_tileSize;}
    QPoint getSize() const {return m_size;}

    enum { Type = UserType + 2 };
    int type() const override { return Type; }

protected:
    Tile& getTile(QPointF position) const;
    bool tileEnabled(QPointF position) const;

private:
    QPoint m_size;
    QPointF m_tileSize;
    QVector<Tile*> m_tiles;
    TileSet *m_tileset;
};

#endif // TILEMAP_H
