#include "basicai.h"

BasicAI::BasicAI()
{

}

int BasicAI::predictNextMove(int stepDirection, int direction, bool collision, int collisionDirection)
{
    if (direction == 0){
        return BasicAI::LEFT;
    }
    if (stepDirection > 50) {
        if (direction == BasicAI::LEFT) {
            return BasicAI::RIGHT;
        }
        else if (direction == BasicAI::RIGHT) {
            return BasicAI::LEFT;
        }

    }

    if (collision) {
        if(collisionDirection != direction) {
            return -direction;
        }
        return direction;
    }
    return direction;
}
