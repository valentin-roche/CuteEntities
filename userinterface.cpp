#include "userinterface.h"

int UserInterface::nbDeath() const
{
    return m_nbDeath;
}

void UserInterface::setNbDeath(int nbDeath)
{
    m_nbDeath = nbDeath;
}

int UserInterface::nbCoin() const
{
    return m_nbCoin;
}

void UserInterface::setNbCoin(int nbCoin)
{
    m_nbCoin = nbCoin;
}

qint64 UserInterface::startTime() const
{
    return m_startTime;
}

void UserInterface::setStartTime(const qint64 &startTime)
{
    m_startTime = startTime;
}

QLabel* UserInterface::deahLabel() const
{
    return m_deahLabel;
}

QLabel* UserInterface::coinLabel() const
{
    return m_coinLabel;
}

QLabel* UserInterface::timeLabel() const
{
    return m_timeLabel;
}

UserInterface::UserInterface()
{
    m_nbDeath = 0;
    m_nbCoin = 0;
    m_startTime = 0;
    m_deahLabel = new QLabel();
    m_coinLabel = new QLabel();
    m_timeLabel = new QLabel();
}

UserInterface::UserInterface(int x_pos, int y_pos)
{
    m_nbDeath = 0;
    m_nbCoin = 0;
    m_startTime = 0;
    m_deahLabel = new QLabel();
    m_coinLabel = new QLabel();
    m_timeLabel = new QLabel();
    m_deahLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    m_coinLabel->setAlignment(Qt::AlignLeft | )

}

