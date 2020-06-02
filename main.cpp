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
    TileSet tileset {":/tileset.json"};
    Scene * view = new Scene(entities, tileset);

    view->show();

    return a.exec();
}
