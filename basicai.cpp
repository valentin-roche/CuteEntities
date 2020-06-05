#include "basicai.h"

BasicAI::BasicAI()
{

}

int BasicAI::predictNextMove(int stepDirection, int direction, bool collision, int collisionDirection)
{
    if (stepDirection > 100) {
        if (direction == BasicAI::LEFT) {
            return BasicAI::RIGHT;
        }
        else if (direction == BasicAI::RIGHT) {
            return BasicAI::LEFT;
        }

    }
    if (stepDirection == 0) {
        return BasicAI::LEFT;
    }

    if (collision) {
        return -collisionDirection;
    }
    return direction;
}
