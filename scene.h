#ifndef SCENE_H
#define SCENE_H

#include "entity.h"
#include "entitymanager.h"

#include <QGraphicsView>

class Scene : public QGraphicsView
{
    Q_OBJECT

private:
    QGraphicsScene scene;
    EntityManager &entities;

public:
    Scene(EntityManager* entities, QWidget *parent=0);
    void doDelta();
};

#endif // SCENE_H
