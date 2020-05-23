#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "entity.h"

#include <QGraphicsItemGroup>
#include <QElapsedTimer>

class EntityManager
{
private:
    QList<Entity*> m_entities;
public:
    EntityManager();
    void add(Entity ent);
    void doDelta(QElapsedTimer *timer);
};

#endif // ENTITYMANAGER_H
