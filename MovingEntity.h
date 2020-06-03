#ifndef MOVINGENTITY_H
#define MOVINGENTITY_H

#include "entity.h"

class MovingEntity : public Entity {
public:
    MovingEntity(QPoint position, QPoint size);
    void correctCollision(QPoint correction);
    void bounce(int intensity);

protected:
    QPointF m_velocity;

    static constexpr int maxFallingVelocity = 3;
    static constexpr float gravityIntencity = 1;
};

#endif // MOVINGENTITY_H
