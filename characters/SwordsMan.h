#ifndef INTERVIEW_SWORDSMAN_H
#define INTERVIEW_SWORDSMAN_H
#include "Character.h"

class SwordsMan : public Character
{
public:

    SwordsMan(World* world, int pos_x, int pos_y); // creating factory new object

    SwordsMan(World* world, int hitPoints, int pos_x, int pos_y, int buildingCounter); // creating Knight probably read from file

    void action() override;

    void move() override;

};

#endif
