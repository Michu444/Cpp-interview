#ifndef INTERVIEW_KNIGHT_H
#define INTERVIEW_KNIGHT_H
#include "Character.h"

class Knight : public Character
{
public:

    Knight(World* world, int posX, int posY, char baseSymbol); // creating factory new object

    Knight(World* world, int hitPoints, int posX, int posY, int buildingCounter, char baseSymbol); // creating Knight probably read from file

    void action() override;

};


#endif
