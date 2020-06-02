#ifndef MOVINGENTITY_H
#define MOVINGENTITY_H

#include "entity.h"

class MovingEntity : public Entity {
public:
    MovingEntity(QPoint position, QPoint size);
    void correctCollision(QPoint correction);

protected:
    QPointF m_velocity;
};

#endif // MOVINGENTITY_H
