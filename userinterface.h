#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QLabel>
#include <QtGlobal>

class UserInterface
{
private :
    int m_nbDeath;
    int m_nbCoin;
    qint64 m_startTime;
    QLabel* m_deahLabel;
    QLabel* m_coinLabel;
    QLabel* m_timeLabel;

public:
    UserInterface();
    UserInterface(QPoint qp_pos);

    int nbDeath() const;
    void setNbDeath(int nbDeath);
    int nbCoin() const;
    void setNbCoin(int nbCoin);
    qint64 startTime() const;
    void setStartTime(const qint64 &startTime);
    QLabel* deahLabel() const;
    QLabel* coinLabel() const;
    QLabel* timeLabel() const;
};

#endif // USERINTERFACE_H
