#ifndef INTERVIEW_PIKEMAN_H
#define INTERVIEW_PIKEMAN_H
#include "Character.h"


class Pikeman : public Character
{
public:

    Pikeman(World* world, int posX, int posY, char baseSymbol);

    Pikeman(World* world, int hitPoints, int posX, int posY, int buildingCounter, char baseSymbol);

    int getAttackValue(const std::string& unitName) const override;
};


#endif
