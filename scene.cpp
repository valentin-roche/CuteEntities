#include "scene.h"

#include <QGraphicsView>

Scene::Scene(QList<Entity>& entities, QWidget *parent): QGraphicsView(parent), entities(entities)
{
    scene.setSceneRect(0, 0, 800, 600);
    setScene(&scene);
}
