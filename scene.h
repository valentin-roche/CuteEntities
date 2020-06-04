#ifndef SCENE_H
#define SCENE_H

#include "entity.h"
#include "entitymanager.h"
#include "TileSet.h"
#include "CenteredTileMap.h"
#include "Player.h"
#include "CollisionHandler.h"
#include "userinterface.h"

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
    UserInterface* m_UI;

    void doDelta();
    bool tileExistsAt(QPoint position);
    void load_from_json();

public:
    Scene(EntityManager& entities, TileSet& tileset, QWidget *parent=0);
    QGraphicsScene * getScene();
    void calculateCollisions();

    UserInterface *getUI() const;

public slots:
    void startRender();
};

struct level_info
{
    int nb_coins;

};

#endif // SCENE_H
