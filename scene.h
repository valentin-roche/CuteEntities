#ifndef SCENE_H
#define SCENE_H

#include "entity.h"
#include "entitymanager.h"
#include "TileSet.h"
#include "CenteredTileMap.h"
#include "Player.h"
#include "CollisionHandler.h"

#include <QGraphicsView>
#include <QElapsedTimer>
#include <QGraphicsView>
#include <QTimer>
#include <QApplication>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

class Scene : public QGraphicsView
{
    Q_OBJECT

private:
    QGraphicsScene scene;
    EntityManager &m_entities;
    QElapsedTimer *main_timer;
    QElapsedTimer *sec_timer;
    QTimer *timer_render;
    int update_for_sec;

    TileSet& m_tileset;
    CenteredTileMap m_tilemap;
    Player m_player;

    void doDelta();
    bool tileExistsAt(QPoint position);
    void load_from_json();

public:
    Scene(EntityManager& entities, TileSet& tileset, QWidget *parent=0);
    QGraphicsScene * getScene();

public slots:
    void startRender();
};

#endif // SCENE_H
