#ifndef INTERVIEW_INSTANCE_H
#define INTERVIEW_INSTANCE_H

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
    char symbol;


public:

    Instance(World *world, int hitPoints, int speed, int cost, int attack_range, int building_time, int pos_x, int pos_y);

    virtual void action() = 0;

    virtual void move() = 0;



};

#endif
