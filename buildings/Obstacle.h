#ifndef INTERVIEW_OBSTACLE_H
#define INTERVIEW_OBSTACLE_H
#include "Building.h"

class Obstacle :public Building
{

public:
    Obstacle(World* world, int posX, int posY);

    void action() override;

    void move() override;
};


#endif
