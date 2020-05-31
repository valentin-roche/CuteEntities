#include "scene.h"

Scene::Scene(EntityManager& entities, QWidget *parent): QGraphicsView(parent), m_entities(entities)
{
    main_timer = new QElapsedTimer();

    timer_render = new QTimer();
    connect(timer_render, SIGNAL(timeout()), this, SLOT(doDelta()));
    timer_render->start(1000);

    qDebug() << "entities : " << m_entities.getEntities();

    for (Entity* e : m_entities.getEntities())
    {
        scene.addItem(e);
        qDebug() << "Ajout de l'entite : " << e;
    }

    scene.setSceneRect(0, 0, 800, 600);
    setScene(&scene);
}

void Scene::doDelta()
{
    m_entities.doDelta(main_timer);
    qDebug() << scene.items();
}

QGraphicsScene * Scene::getScene()
{
    return &scene;
}
