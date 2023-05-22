#ifndef INTERVIEW_RAM_H
#define INTERVIEW_RAM_H
#include "Character.h"

class Ram : public Character
{
public:

    Ram(World* world, int posX, int posY, char baseSymbol);

    Ram(World* world, int hitPoints, int posX, int posY, int buildingCounter, char baseSymbol);

    int getAttackValue(const std::string& unitName) const override;
};


#endif
