#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QLabel>
#include <QtGlobal>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QGraphicsItemGroup>
#include <QElapsedTimer>


class UserInterface
{

public:
    UserInterface();
    UserInterface(int x_pos, int y_pos,QElapsedTimer* timer);

    int nbDeath() const;
    void setNbDeath(int nbDeath);
    int nbCoin() const;
    void setNbCoin(int nbCoin);
    QGraphicsTextItem* deathLabel() const;
    QGraphicsTextItem* coinLabel() const;
    QGraphicsTextItem* timeLabel() const;
    QGraphicsItemGroup *display() const;
    void updateCoin();
    void updateDeath();
    void updateTimer();

private:
    int m_nbDeath;
    int m_nbCoin;
    QGraphicsTextItem* m_deathLabel;
    QGraphicsTextItem* m_coinLabel;
    QGraphicsTextItem* m_timeLabel;
    QGraphicsItemGroup* m_display;
    QElapsedTimer* m_timer;
    qint64 m_startTime;

};

#endif // USERINTERFACE_H
