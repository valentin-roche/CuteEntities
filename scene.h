#ifndef SCENE_H
#define SCENE_H

#include "entity.h"
#include "entitymanager.h"

#include <QGraphicsView>
#include <QElapsedTimer>
#include <QGraphicsView>
#include <QTimer>
#include <QDebug>

class Scene : public QGraphicsView
{
    Q_OBJECT

private:
    QGraphicsScene scene;
    EntityManager &m_entities;
    QElapsedTimer *main_timer;
    QTimer *timer_render;

public:
    Scene(EntityManager& entities, QWidget *parent=0);
    QGraphicsScene * getScene();

public slots:
    void doDelta();

};

#endif // SCENE_H
