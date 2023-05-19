#ifndef INTERVIEW_BASE_H
#define INTERVIEW_BASE_H
#include "Building.h"

class GoldMine : public Building
{
    bool occupied;

public:
    GoldMine(World* world, int posX, int posY);

    void action() override;

    void move() override;
};

#endif