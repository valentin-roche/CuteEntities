#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "Player.h"
#include "entity.h"
#include "enemy.h"
#include "coin.h"

#include <QElapsedTimer>
#include <QGraphicsScene>
#include <QJsonArray>
#include <QJsonObject>

class EntityManager
{
private:
    QList<Entity*> m_entities;
    Player *m_player;

public:
    EntityManager();
    void add(Entity *ent);
    void doDelta(QElapsedTimer *timer);
    QList<Entity*> getEntities();
    void loadFromJson(QJsonArray json_ent_array);
    void setPlayer(Player *player);
    void killEnemy(Enemy *enemy);
    void killPlayer(Player *player);
    void getCoin(Coin *coin);
};

#endif // ENTITYMANAGER_H
