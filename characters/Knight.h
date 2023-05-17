#ifndef INTERVIEW_KNIGHT_H
#define INTERVIEW_KNIGHT_H
#include "Character.h"

class Knight : public Character
{

public:

    Knight(World* world, int hitPoints, int speed, int cost, int attack_range, int building_time, int pos_x, int pos_y);

    void action() override;

    void move() override;


};


#endif
