#ifndef INTERVIEW_ARCHER_H
#define INTERVIEW_ARCHER_H
#include "Character.h"

class Archer : public Character
{
public:

    Archer(World* world, int posX, int posY, char baseSymbol);

    Archer(World* world, int hitPoints, int posX, int posY, int buildingCounter, char baseSymbol);

    int getAttackValue(const std::string& unitName) const override;
};


#endif
