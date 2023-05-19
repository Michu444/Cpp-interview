#ifndef INTERVIEW_KNIGHT_H
#define INTERVIEW_KNIGHT_H
#include "Character.h"

class Knight : public Character
{
public:

    Knight(World* world, int posX, int posY); // creating factory new object

    Knight(World* world, int hitPoints, int posX, int posY, int buildingCounter); // creating Knight probably read from file

    void action() override;

    void move() override;

};


#endif
