#ifndef MOVINGENTITY_H
#define MOVINGENTITY_H

#include "entity.h"

class MovingEntity : public Entity {
public:
    MovingEntity(QPoint position, QPoint size);
    void correctCollision(QPoint correction);

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
};

#endif // MOVINGENTITY_H
