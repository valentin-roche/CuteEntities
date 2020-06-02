#ifndef BASICAI_H
#define BASICAI_H


class BasicAI
{
public:
    BasicAI();
    static int predictNextMove(int stepDirection, int direction, bool collision, int collisionDirection);

    const static int LEFT = -100;
    const static int RIGHT = 100;
};

#endif // BASICAI_H
