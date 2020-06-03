#ifndef CENTEREDTILEMAP_H
#define CENTEREDTILEMAP_H

#include "TileMap.h"
#include <QElapsedTimer>
#include <QPoint>

class CenteredTileMap : public TileMap {

public:
    CenteredTileMap(TileSet* tileset, QPoint viewSize);
    CenteredTileMap(TileSet* tileset, QJsonObject size, QJsonArray tiles, QPoint viewSize);

    void setViewSize(QPoint viewSize);
    void updatePlayerPosition(QPoint playerPosition);
    float getOffsetX() { return m_offsetX; }

    void collapseTile(QPoint position);

private:
    QPoint m_viewSize;
    float m_offsetX;

    static constexpr int collapseDelayMs = 750;

    QVector<QElapsedTimer> m_collapseTimers;
    QVector<QPoint> m_collapsePositions;
};

#endif // CENTEREDTILEMAP_H
