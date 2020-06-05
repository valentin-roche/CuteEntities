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

QGraphicsSimpleTextItem *UserInterface::victoryLabel() const
{
    return m_victoryLabel;
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
    m_deathLabel->setFont(QFont( "Helvetica", 12 ));
    m_coinLabel->setFont(QFont( "Helvetica", 12 ));
    m_timeLabel->setFont(QFont( "Helvetica", 12 ));
    m_deathLabel->setPlainText(("Nombre de mort : "+QString::number(m_nbDeath)));
    m_coinLabel->setPlainText("Nombre de pièces : "+QString::number(m_nbCoin));
    m_timeLabel->setPlainText("Temps : "+QString::number((m_timer->elapsed()-m_startTime)/1000));
    m_deathLabel->setPos(x_pos,y_pos);
    m_coinLabel->setPos(x_pos,y_pos+20);
    m_timeLabel->setPos(x_pos,y_pos+40);
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

QGraphicsSimpleTextItem* UserInterface::displayVictory()
{
    m_victoryLabel = new QGraphicsSimpleTextItem();
    m_victoryLabel->setFont(QFont( "Helvetica", 64 ));
    m_victoryLabel->setText( QString::fromLatin1( "VICTOIRE" ) );
    QRectF bR = m_victoryLabel->sceneBoundingRect();
    m_victoryLabel->setPos( 400 - bR.width()/2, 300 - bR.height()/2 );
    m_display->addToGroup(m_victoryLabel);
    return m_victoryLabel;
}
