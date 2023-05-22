#ifndef INTERVIEW_KNIGHT_H
#define INTERVIEW_KNIGHT_H
#include "Character.h"

class Knight : public Character
{
public:

    Knight(World* world, int posX, int posY, char baseSymbol);

    Knight(World* world, int hitPoints, int posX, int posY, int buildingCounter, char baseSymbol);

    int getAttackValue(const std::string& unitName) const override;
};


#endif
