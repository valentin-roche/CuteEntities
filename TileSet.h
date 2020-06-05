#ifndef TILESET_H
#define TILESET_H

#include <algorithm>

#include <QString>
#include <QPointF>
#include <QImage>
#include <QDebug>

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class TileSet {

public:
    TileSet(QString imagePath, QPoint tileSize, QPoint size, QPoint tileOffset = {0, 0});
    TileSet(QString jsonDescriptorPath);

    QPointF getTileSize() const;
    const QImage& getImage() const;
    QRectF getTileRect(QString name) const;

    bool hasCollision(QString name) const;
    bool hasWin(QString name) const;
    bool hasKill(QString name) const;
    bool hasCollapse(QString name) const;
    bool hasBounce(QString name) const;
    bool hasCoin(QString name) const;

private:
    QImage m_image;
    QPoint m_tileSize;
    QPoint m_size;
    QPoint m_tileOffset;

    struct TileDescriptor {
        QString name;
        QPoint position;
        bool collision;
        bool win;
        bool kill;
        bool collapse;
        bool bounce;
        bool coin;
    };

    QVector<TileDescriptor> m_tileDescriptors;

    const TileDescriptor& getTileDescriptor(QString name) const;
    void addTileDescriptor(QJsonObject& descriptor);
};

#endif // TILESET_H
