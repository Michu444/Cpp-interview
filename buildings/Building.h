#ifndef INTERVIEW_BUILDING_H
#define INTERVIEW_BUILDING_H
#include "../Instance.h"

class Building :public Instance
{

public:
    Building(World* world, int hitPoints, int speed, int cost, int attack_range, int building_time, int pos_x, int pos_y);

    void action() override;

    void move() override;

    int getPosX() override;
    int getPosY() override;


};

#endif
