#include "entitymanager.h"

EntityManager::EntityManager()
{

}

void EntityManager::add(Entity* ent)
{
    m_entities << ent;
}

void EntityManager::doDelta(QElapsedTimer* timer)
{
    for(int ent_index = 0; ent_index < m_entities.length(); ent_index++)
    {
        m_entities[ent_index]->delta(timer->elapsed());
    }
}

QList<Entity*> EntityManager::getEntities()
{
    return m_entities;
}

void EntityManager::loadFromJson(QJsonArray json_ent_array)
{
    for (auto entInfoRaw : json_ent_array)
    {
        QJsonObject entInfo = entInfoRaw.toObject();

        QJsonObject positionObject = entInfo["position"].toObject();
        QPoint position {positionObject["x"].toInt(), positionObject["y"].toInt()};

        QString entType = entInfo["type"].toString();

        if (entType == "player")
        {
            m_player->setPosition(position);
        }
        if (entType == "basicEnnemy")
        {
            Enemy *e = new Enemy(position, {10, 10});
            m_entities.append(e);
        }
        if (entType == "coin")
        {
            Coin *c = new Coin(position, {5, 5});
            m_entities.append(c);
        }
    }
}


void EntityManager::setPlayer(Player *player)
{
    m_player = player;
}

void EntityManager::killEnemy(Enemy *enemy)
{
    m_entities.removeAt(m_entities.indexOf(enemy));
}

void EntityManager::killPlayer(Player *player)
{
    emit playerDead();
}

void EntityManager::getCoin(Coin *coin)
{
    m_entities.removeAt(m_entities.indexOf(coin));
    emit coinGet();
}

void EntityManager::clearEntities()
{
    m_entities.clear();
}
