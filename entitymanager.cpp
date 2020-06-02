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
    qDebug() << "starting delta at : " << timer->elapsed();
    for(int ent_index = 0; ent_index < m_entities.length(); ent_index++)
    {
        m_entities[ent_index]->delta(timer->elapsed());
    }
}

QList<Entity*> EntityManager::getEntities()
{
    return m_entities;
}

void EntityManager::load_from_json(QJsonArray json_ent_array)
{
    for (auto entInfoRaw : json_ent_array)
    {
        QJsonObject entInfo = entInfoRaw.toObject();

        QJsonObject positionObject = entInfo["position"].toObject();
        QPoint position {positionObject["x"].toInt(), positionObject["y"].toInt()};

        QString entType = entInfo["type"].toString();

        /*if (entType == "ent")
        {
            Entity *e = new Entity(position, 20, 20);
            m_entities.append(e);
        }*/
    }
}
