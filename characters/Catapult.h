#ifndef INTERVIEW_CATAPULT_H
#define INTERVIEW_CATAPULT_H
#include "Character.h"

class Catapult : public Character
{
public:

    Catapult(World* world, int posX, int posY, char baseSymbol);

    Catapult(World* world, int hitPoints, int posX, int posY, int buildingCounter, char baseSymbol);

    int getAttackValue(const std::string& unitName) const override;
};


#endif
