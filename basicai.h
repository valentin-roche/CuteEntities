#ifndef BASICAI_H
#define BASICAI_H


class BasicAI
{
public:
    BasicAI();
    static int predictNextMove(int stepDirection, int direction, bool collision, int collisionDirection);

    const static int LEFT = 1;
    const static int RIGHT = -1;
};

#endif // BASICAI_H
