#include "scene.h"

Scene::Scene(EntityManager& entities, QWidget *parent): QGraphicsView(parent), m_entities(entities)
{
    main_timer = new QElapsedTimer();

    timer_render = new QTimer();
    timer_render->setSingleShot(true);
    connect(timer_render, SIGNAL(timeout()), this, SLOT(doDelta()));

    qDebug() << "entities : " << m_entities.getEntities();

    for (Entity* e : m_entities.getEntities())
    {
        scene.addItem(e);
        qDebug() << "Ajout de l'entite : " << e;
    }

    scene.setSceneRect(0, 0, 800, 600);
    setScene(&scene);

    sec_timer = new QElapsedTimer();
    update_for_sec = 0;
    qDebug() << QString::number(sec_timer->elapsed());
    while(true)
    {
        if (sec_timer->elapsed() < 990)
        {
            update_for_sec ++;
        }
        else
        {
            update_for_sec = 0;
            sec_timer->restart();
        }
        timer_render->start(1000 - sec_timer->elapsed() / 60 - update_for_sec);
        QApplication::processEvents();
    }

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
