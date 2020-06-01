#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "entity.h"

#include <QElapsedTimer>
#include <QGraphicsScene>

class EntityManager
{
private:
    QList<Entity*> m_entities;
public:
    EntityManager();
    void add(Entity *ent);
    void doDelta(QElapsedTimer *timer);
    QList<Entity*> getEntities();
};

#endif // ENTITYMANAGER_H
