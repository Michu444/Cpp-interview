#ifndef INTERVIEW_KNIGHT_H
#define INTERVIEW_KNIGHT_H
#include "Character.h"

class Knight : public Character
{
public:

    Knight(World* world, int pos_x, int pos_y); // creating factory new object

    Knight(World* world, int hitPoints, int pos_x, int pos_y, int buildingCounter); // creating Knight probably read from file

    void action() override;

    void move() override;

};


#endif
