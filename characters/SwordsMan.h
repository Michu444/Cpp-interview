#ifndef INTERVIEW_SWORDSMAN_H
#define INTERVIEW_SWORDSMAN_H
#include "Character.h"

class SwordsMan : public Character
{
public:

    SwordsMan(World* world, int posX, int posY); // creating factory new object

    SwordsMan(World* world, int hitPoints, int posX, int posY, int buildingCounter); // creating Knight probably read from file

    void action() override;

    void move() override;

};

#endif
