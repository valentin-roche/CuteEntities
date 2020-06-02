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

    //Entity ent {QPointF(100, 100), 32, 32};

    //entities.add(&ent);

    Scene * view = new Scene(entities);

    view->show();

    return a.exec();
}
