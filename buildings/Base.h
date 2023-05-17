#ifndef INTERVIEW_BASE_H
#define INTERVIEW_BASE_H

#include "Building.h"

class Base : public Building
{
public:
    Base(World* world, int hitPoints, int speed, int cost, int attack_range, int building_time, int pos_x, int pos_y);

    void action() override;

    void move() override;
};

#endif