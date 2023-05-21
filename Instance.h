#ifndef INTERVIEW_INSTANCE_H
#define INTERVIEW_INSTANCE_H
#include <iostream>
#include <string>
#include <conio.h>

class World;

class Instance
{
protected:
    World *world;
    int posX, posY;
    int hitPoints;
    int speed;
    int cost;
    int attack_range;
    int building_time;
    std::string name;
    int buildingCounter{};
    bool movePossible{};



public:

    Instance(World *world, int hitPoints, int speed, int cost, int attack_range, int building_time, int posX, int posY);

    virtual void action() = 0;

    virtual void move() = 0;

    virtual char getSymbol() = 0;

    virtual int getPosX() = 0;

    virtual int getPosY() = 0;

    virtual int getHitPoints();

    virtual std::string getName();

    virtual bool getMovePossible();

    virtual void setMovePossible(bool status);

    // global inheritance for future creating building by base
    virtual int getBuildingCounter();
    virtual void setBuildingCounter(int buildingCounter);

    virtual ~Instance();
};

#endif
