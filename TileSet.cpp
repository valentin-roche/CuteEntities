#include "TileSet.h"

TileSet::TileSet(QString imagePath, QPoint tileSize, QPoint size, QPoint tileOffset) :
    m_tileSize(tileSize), m_size(size), m_tileOffset(tileOffset)
{
    m_image.load(imagePath);
}

TileSet::TileSet(QString jsonDescriptorPath)
{
    // Read json file
    QFile file;
    file.setFileName(jsonDescriptorPath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QString val = file.readAll();
    QJsonDocument document = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject mainObject = document.object();

    // Load the image containing all tiles
    QString imagePath = mainObject["image"].toString();
    m_image.load(imagePath);

    // Read sizes
    QJsonObject size = mainObject["size"].toObject();
    m_size = {size["x"].toInt(), size["y"].toInt()};

    QJsonObject tileSize = mainObject["tileSize"].toObject();
    m_tileSize = {tileSize["x"].toInt(), tileSize["y"].toInt()};

    QJsonObject tileOffset = mainObject["tileOffset"].toObject();
    m_tileOffset = {tileOffset["x"].toInt(), tileOffset["y"].toInt()};

    // Read tile descriptors
    QJsonArray tileDescriptors = mainObject["tiles"].toArray();

    for (auto tileDescriptorRef : tileDescriptors) {
        QJsonObject tileDescriptor = tileDescriptorRef.toObject();
        addTileDescriptor(tileDescriptor);
    }
}

QPointF TileSet::getTileSize() const
{
    return m_tileSize;
}

const QImage &TileSet::getImage() const
{
    return m_image;
}

QRectF TileSet::getTileRect(QString name) const
{
    auto &descriptor = getTileDescriptor(name);
    const QPoint &position = descriptor.position;

    return QRectF{(float) position.x() * (m_tileSize.x() + m_tileOffset.x()),
                (float) position.y() * (m_tileSize.y() + m_tileOffset.y()),
                (float) m_tileSize.x(), (float) m_tileSize.y()};
}

bool TileSet::hasCollision(QString name) const
{
    return getTileDescriptor(name).collision;
}

bool TileSet::hasWin(QString name) const
{
    return getTileDescriptor(name).win;
}

bool TileSet::hasKill(QString name) const
{
    return getTileDescriptor(name).kill;
}

bool TileSet::hasCollapse(QString name) const
{
    return getTileDescriptor(name).collapse;
}

bool TileSet::hasBounce(QString name) const
{
    return getTileDescriptor(name).bounce;
}

bool TileSet::hasCoin(QString name) const
{
    return getTileDescriptor(name).coin;
}

const TileSet::TileDescriptor &TileSet::getTileDescriptor(QString name) const
{
    auto descriptor = std::find_if(m_tileDescriptors.begin(), m_tileDescriptors.end(), [&name](const TileDescriptor& value) {
       return value.name == name;
    });

    return *descriptor;
}

void TileSet::addTileDescriptor(QJsonObject &descriptor)
{
    QString tileName = descriptor["name"].toString();
    QJsonObject tilePositionObject = descriptor["position"].toObject();
    QPoint tilePosition = {tilePositionObject["x"].toInt(), tilePositionObject["y"].toInt()};

    bool collapse = false;
    if (descriptor.contains("collapse") && descriptor["collapse"].toBool()) collapse = true;

    bool win = false;
    if (descriptor.contains("win") && descriptor["win"].toBool()) win = true;

    bool kill = false;
    if (descriptor.contains("kill") && descriptor["kill"].toBool()) kill = true;

    bool bounce = false;
    if (descriptor.contains("bounce") && descriptor["bounce"].toBool()) bounce = true;

    bool coin = false;
    if (descriptor.contains("coin") && descriptor["coin"].toBool()) coin = true;

    m_tileDescriptors.push_back({tileName, tilePosition, descriptor["collision"].toBool(), win, kill, collapse, bounce, coin});
}

