#ifndef INTERVIEW_GOLDMINE_H
#define INTERVIEW_GOLDMINE_H
#include "Building.h"

class GoldMine : public Building
{
    bool occupied;
    int goldPerRound = 50;

public:
    GoldMine(World* world, int posX, int posY);

    char getSymbol() override;

};

#endif