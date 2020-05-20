#ifndef SCENE_H
#define SCENE_H

#include "entity.h"

#include <QGraphicsView>

class Scene : public QGraphicsView
{
    Q_OBJECT

private:
    QList<Entity>& entities;
    QGraphicsScene scene;
    QGraphicsItemGroup entities_graph;

public:
    Scene(QList<Entity>& entities, QWidget *parent=0);
};

#endif // SCENE_H
