#ifndef INTERVIEW_INSTANCE_H
#define INTERVIEW_INSTANCE_H
#include <iostream>

class World;

class Instance
{
protected:
    World *world;
    int pos_x, pos_y;
    int hitPoints;
    int speed;
    int cost;
    int attack_range;
    int building_time;


public:

    Instance(World *world, int hitPoints, int speed, int cost, int attack_range, int building_time, int pos_x, int pos_y);

    virtual void action() = 0;

    virtual void move() = 0;

    virtual char getSymbol() = 0;

    virtual int getPosX() = 0;

    virtual int getPosY() = 0;

    virtual ~Instance();
};

#endif
