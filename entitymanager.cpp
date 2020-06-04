#include "entitymanager.h"

EntityManager::EntityManager()
{

}

void EntityManager::add(Entity* ent)
{
    m_entities << ent;
    //qDebug() << m_entities;
}

void EntityManager::doDelta(QElapsedTimer* timer)
{
    //qDebug() << "starting delta at : " << timer->elapsed();
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
            //qDebug() << "Setting  player's spawn point at : " << position;
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
    delete(enemy);
}

void EntityManager::killPlayer(Player *player)
{
    qDebug() << "DED NOT BIG SUPRISE";
}

void EntityManager::getCoin(Coin *coin)
{
    qDebug() << "toudoum";
    m_entities.removeAt(m_entities.indexOf(coin));
}
