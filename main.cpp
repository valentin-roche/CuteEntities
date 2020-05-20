#include "entity.h"
#include "scene.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QList<Entity> entities;

    Scene * view = new Scene(entities);

    view->show();

    return a.exec();
}
