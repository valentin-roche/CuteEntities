#ifndef SCENE_H
#define SCENE_H

#include "entity.h"
#include "entitymanager.h"

#include <QGraphicsView>
#include <QElapsedTimer>
#include <QGraphicsView>
#include <QTimer>
#include <QApplication>

class Scene : public QGraphicsView
{
    Q_OBJECT

private:
    QGraphicsScene scene;
    EntityManager &m_entities;
    QElapsedTimer *main_timer;
    QElapsedTimer *sec_timer;
    QTimer *timer_render;
    int update_for_sec;

public:
    Scene(EntityManager& entities, QWidget *parent=0);
    QGraphicsScene * getScene();

public slots:
    void doDelta();

};

#endif // SCENE_H
