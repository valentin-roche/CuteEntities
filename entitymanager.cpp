#include "entitymanager.h"

EntityManager::EntityManager()
{

}

void EntityManager::add(Entity* ent)
{
    m_entities << ent;
    qDebug() << m_entities;
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
