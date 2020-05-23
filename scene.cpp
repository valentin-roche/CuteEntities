#include "scene.h"

#include <QElapsedTimer>
#include <QGraphicsView>

Scene::Scene(EntityManager* entities, QWidget *parent): QGraphicsView(parent), entities(*entities)
{
    scene.setSceneRect(0, 0, 800, 600);
    setScene(&scene);
}

void Scene::doDelta()
{
    QElapsedTimer *timer = new QElapsedTimer();
    timer->start();

    while(true)
    {
        entities.doDelta(timer);
    }
}
