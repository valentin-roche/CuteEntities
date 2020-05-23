#include "entitymanager.h"

EntityManager::EntityManager()
{

}

void EntityManager::add(Entity* ent)
{
    m_entities.append(ent);
}

void EntityManager::doDelta(QElapsedTimer* timer)
{
    qDebug() << "starting delta at : " << timer->nsecsElapsed();
    for(int ent_index = 0; ent_index < m_entities.length(); ent_index++)
    {
        m_entities[ent_index]->delta(timer->nsecsElapsed());
    }
}
