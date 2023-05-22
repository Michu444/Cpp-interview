#ifndef INTERVIEW_WORKER_H
#define INTERVIEW_WORKER_H
#include "Character.h"

class Worker :public Character
{
public:

    Worker(World* world, int posX, int posY, char baseSymbol);

    Worker(World* world, int hitPoints, int posX, int posY, int buildingCounter, char baseSymbol);

    int getAttackValue(const std::string& unitName) const override;
};


#endif
