#ifndef INTERVIEW_SWORDSMAN_H
#define INTERVIEW_SWORDSMAN_H
#include "Character.h"

class Swordsman : public Character
{
public:

    Swordsman(World* world, int posX, int posY, char baseSymbol);

    Swordsman(World* world, int hitPoints, int posX, int posY, int buildingCounter, char baseSymbol);

    int getAttackValue(const std::string& unitName) const override;
};

#endif
