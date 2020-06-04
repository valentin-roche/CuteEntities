#include "userinterface.h"

#include <QTextCharFormat>
#include <QTextCursor>

int UserInterface::nbDeath() const
{
    return m_nbDeath;
}

void UserInterface::setNbDeath(int nbDeath)
{
    m_nbDeath = nbDeath;
    m_deathLabel->setPlainText("Nombre de mort : "+QString::number(m_nbDeath));
}

int UserInterface::nbCoin() const
{
    return m_nbCoin;
}

void UserInterface::setNbCoin(int nbCoin)
{
    m_nbCoin = nbCoin;
    m_coinLabel->setPlainText("Nombre de pièces : "+QString::number(m_nbCoin));
}


QGraphicsTextItem* UserInterface::deathLabel() const
{
    return m_deathLabel;
}

QGraphicsTextItem* UserInterface::coinLabel() const
{
    return m_coinLabel;
}

QGraphicsTextItem* UserInterface::timeLabel() const
{
    return m_timeLabel;
}

QGraphicsItemGroup *UserInterface::display() const
{
    return m_display;
}

UserInterface::UserInterface()
{
    m_nbDeath = 0;
    m_nbCoin = 0;
    m_deathLabel = new QGraphicsTextItem();
    m_coinLabel = new QGraphicsTextItem();
    m_timeLabel = new QGraphicsTextItem();
    m_timer = new QElapsedTimer();
}

UserInterface::UserInterface(int x_pos, int y_pos,QElapsedTimer* timer) : m_timer(timer)
{
    m_startTime = m_timer->elapsed();
    m_nbDeath = 0;
    m_nbCoin = 0;
    m_deathLabel = new QGraphicsTextItem();
    m_coinLabel = new QGraphicsTextItem(m_deathLabel);
    m_timeLabel = new QGraphicsTextItem(m_deathLabel);
    m_deathLabel->setDefaultTextColor(Qt::white);
    m_coinLabel->setDefaultTextColor(Qt::white);
    m_timeLabel->setDefaultTextColor(Qt::white);
    m_deathLabel->setPlainText(("Nombre de mort : "+QString::number(m_nbDeath)));
    m_coinLabel->setPlainText("Nombre de pièces : "+QString::number(m_nbCoin));
    m_timeLabel->setPlainText("Temps : "+QString::number((m_timer->elapsed()-m_startTime)/1000));
    m_deathLabel->setPos(x_pos,y_pos);
    m_coinLabel->setPos(x_pos,y_pos+15);
    m_timeLabel->setPos(x_pos,y_pos+30);
    m_display = new QGraphicsItemGroup();
    m_display->addToGroup(m_deathLabel);
    m_display->addToGroup(m_coinLabel);
    m_display->addToGroup(m_timeLabel);
    m_display->setPos(x_pos,y_pos);
}

void UserInterface::updateCoin()
{
    m_nbCoin++;
    m_coinLabel->setPlainText("Nombre de pièces : "+QString::number(m_nbCoin));
}

void UserInterface::updateDeath()
{
    m_nbDeath++;
    m_deathLabel->setPlainText("Nombre de mort : "+QString::number(m_nbDeath));
}

void UserInterface::updateTimer()
{
    m_timeLabel->setPlainText("Temps : "+QString::number((m_timer->elapsed()-m_startTime)/1000));
}
