#ifndef MOVINGENTITY_H
#define MOVINGENTITY_H

#include "entity.h"

class MovingEntity : public Entity {
public:
    MovingEntity(QPoint position, QPoint size);
    void correctCollision(QPoint correction);
    void bounce(int intensity);

    bool downTileEntity() const;
    void setDownTileEntity(bool downTileEntity);

    bool rightTileEntity() const;
    void setRightTileEntity(bool rightTileEntity);

    bool leftTileEntity() const;
    void setLeftTileEntity(bool leftTileEntity);

protected:
    QPointF m_velocity;
    bool m_leftTileEntity = false;
    bool m_rightTileEntity = false;
    bool m_downTileEntity = false;

    static constexpr int maxFallingVelocity = 3;
    static constexpr float gravityIntancity = 1;

    enum MovingDirection {
        Right = 0,
        Left = 1
    };

    void updateSpriteDirection();
    void updateSprite();
};

#endif // MOVINGENTITY_H
