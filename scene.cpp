#include "scene.h"

Scene::Scene(EntityManager& entities, TileSet& tileset, QWidget *parent):
    QGraphicsView(parent), m_entities(entities), m_tileset(tileset), m_tilemap(&tileset, {800, 20}), m_player({800, 600})
{
    m_entities.setPlayer(&m_player);
    load_from_json();
    main_timer = new QElapsedTimer();

    timer_render = new QTimer();
    timer_render->setSingleShot(true);

    /*m_playlist = new QMediaPlaylist();
    m_playlist->addMedia(QUrl(":/music.mp3"));
    m_playlist->setPlaybackMode(QMediaPlaylist::Loop);

    m_music = new QMediaPlayer();
    m_music->setPlaylist(m_playlist);
    m_music->play();*/

    connect(timer_render, SIGNAL(timeout()), this, SLOT(startRender()));
    connect(&m_entities, SIGNAL(coinGet()), this, SLOT(updateCoin()));
    connect(&m_entities, SIGNAL(playerDead()), this, SLOT(playerDeath()));

    scene.setSceneRect(0, 0, 800, 600);
    scene.addItem(&m_tilemap);

    m_player.setFlag(QGraphicsItem::ItemIsFocusable);
    m_player.setFocus();

    m_UI = new UserInterface(0,0,main_timer);
    scene.addItem(m_UI->display());

    m_entities.add(&m_player);

    for (Entity* e : m_entities.getEntities())
    {
        scene.addItem(e);
    }

    setScene(&scene);
    setBackgroundBrush(QBrush(QColor::fromRgb(162, 216, 255)));
    sec_timer = new QElapsedTimer();
    update_for_sec = 0;

    timer_render->start(0);
}

UserInterface *Scene::getUI() const
{
    return m_UI;
}

void Scene::doDelta()
{
    calculateCollisions();

    auto *itemUnder = itemAt({(int) m_player.pos().x() + (int) (m_player.boundingRect().width() / 2),
                              (int) (m_player.pos().y() + m_player.boundingRect().height() + 2)});
    if (Tile *tileUnder = qgraphicsitem_cast<Tile*>(itemUnder)) {
        if (tileUnder->hasBounce()) {
            m_player.bounce(20);
        }
        if (tileUnder->hasCollapse()) {
            m_tilemap.collapseTile(tileUnder->getTilePosition());
        }
    }

    m_player.setFocus();
    m_entities.doDelta(main_timer);

    for(auto item : m_player.collidingItems()) {
        if (Tile* tile = qgraphicsitem_cast<Tile*>(item)) {
            if (tile->hasCollision()) {
                CollisionHandler::playerTile(&m_player, tile, m_tilemap.getOffsetX());

                if (tile->hasCollapse()) {
                    m_tilemap.collapseTile(tile->getTilePosition());
                }

                if (tile->hasCoin()) {
                    m_tilemap.disableTile(tile->getTilePosition());
                    Coin* coin = new Coin({ (int) (tile->getTilePosition().x() * m_tilemap.getTileSize().x()),
                                            (int) (tile->getTilePosition().y() * m_tilemap.getTileSize().y())},
                                          {800, 600});
                    scene.addItem(coin);
                    m_entities.add(coin);
                }
            }

            if (tile->hasWin()) {
                qDebug() << "pos";
                timer_render->stop();
            } else if (tile->hasKill()) {
                m_entities.killPlayer(&m_player);
                break;
            }
        }

        if (Enemy* enemy = qgraphicsitem_cast<Enemy*>(item)) {
            if (CollisionHandler::playerEnemy(&m_player, enemy, m_tilemap.getOffsetX(), &m_entities)) {
                scene.removeItem(item);
            }
        }

        if (Coin* coin = qgraphicsitem_cast<Coin*>(item)) {
            CollisionHandler::playerCoin(&m_player, coin, m_tilemap.getOffsetX(), &m_entities);
            scene.removeItem(item);
        }
    }

    m_tilemap.update();
    m_tilemap.updatePlayerPosition(m_player.getPosition());
}

void Scene::calculateCollisions()
{
    for (Entity *e : m_entities.getEntities())
    {
        e->setTileMapOffset(m_tilemap.getOffsetX());
        if (!e->getIsMoving()) continue;

        if(MovingEntity* ent = qgraphicsitem_cast<MovingEntity*>(e))
        {
            ent->setDownTileEntity(tileExistsAt({(int) ent->pos().x(), (int) (ent->pos().y() + ent->boundingRect().height() + 2)}));
            ent->setRightTileEntity(tileExistsAt({(int) (ent->pos().x() + ent->boundingRect().width()) + 2, (int) (ent->pos().y() + ent->boundingRect().height() - 2)}));
            ent->setLeftTileEntity(tileExistsAt({(int) (ent->pos().x() - 2), (int) (ent->pos().y() + ent->boundingRect().height() - 2)}));
        }
    }
}

bool Scene::tileExistsAt(QPoint position) const
{
    QGraphicsItem *item = itemAt(position);
    auto *tile = qgraphicsitem_cast<Tile*>(item);
    return item != nullptr && tile != nullptr && tile->isEnabled() && tile->hasCollision();
}

QGraphicsScene * Scene::getScene()
{
    return &scene;
}

void Scene::startRender()
{
    if (sec_timer->elapsed() < 1000 && update_for_sec < 59)
    {
        update_for_sec ++;
    }
    else
    {
        update_for_sec = 0;
        sec_timer->restart();
        m_UI->updateTimer();
    }

    int time = (1000 - sec_timer->elapsed()) / (60 - update_for_sec);

    if (time < 0) {
        time = 0;
    }
    timer_render->start(time);

    this->doDelta();
}

void Scene::updateCoin()
{
    m_nb_coins++;
    m_UI->setNbCoin(m_nb_coins);
}

void Scene::playerDeath()
{
    m_nb_deaths++;
    m_UI->setNbDeath(m_nb_deaths);
    m_nb_coins = 0;
    m_UI->setNbCoin(m_nb_coins);
    reset();
}

void Scene::reset()
{

    for (QGraphicsItem *item : scene.items()) {
        if (item != &m_player && item != &m_tilemap && item != m_UI->display() && item->parentItem() != m_UI->display()) {
            scene.removeItem(item);
        }
    }

    m_entities.clearEntities();

    m_entities.add(&m_player);
    m_entities.setPlayer(&m_player);
    load_from_json();

    for (Entity* e : m_entities.getEntities())
    {
        if (e != &m_player)
            scene.addItem(e);
    }
}

void Scene::load_from_json()
{
    //Load map and entities
    QFile file;
    file.setFileName(":/map.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QString val = file.readAll();
    QJsonDocument document = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject mainObject = document.object();

    QJsonObject size = mainObject["size"].toObject();
    QJsonArray tiles = mainObject["map"].toArray();
    m_tilemap.loadMap(size, tiles);

    QJsonArray ent = mainObject["entities"].toArray();
    m_entities.loadFromJson(ent);
}
