#ifndef COIN_H
#define COIN_H

#include "entity.h"
#include <QGraphicsRectItem>

class Coin : public Entity
{
public:
    Coin(QPoint position, QPoint viewSize);
    void delta(qint64 elapsed) override;

    enum { Type = UserType + 20 };
    int type() const override { return Type; }

private:
    QPoint m_viewSize;
};

#endif // COIN_H
