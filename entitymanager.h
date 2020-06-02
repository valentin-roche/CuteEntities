#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "entity.h"

#include <QElapsedTimer>
#include <QGraphicsScene>
#include <QJsonArray>
#include <QJsonObject>

class EntityManager
{
private:
    QList<Entity*> m_entities;
public:
    EntityManager();
    void add(Entity *ent);
    void doDelta(QElapsedTimer *timer);
    QList<Entity*> getEntities();
    void load_from_json(QJsonArray json_ent_array);
};

#endif // ENTITYMANAGER_H
