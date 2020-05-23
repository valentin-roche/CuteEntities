#include "entity.h"
#include "entitymanager.h"
#include "scene.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    EntityManager entities;

    Scene * view = new Scene(&entities);

    Entity ent {QPointF(0, 0), 32, 32};

    entities.add(&ent);

    view->show();
    view->doDelta();

    return a.exec();
}
