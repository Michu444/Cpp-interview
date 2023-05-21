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
    int attackRange;
    int buildingTime;
    std::string name;
    int buildingCounter{};
    bool movePossible{};
    char symbol{};
    char baseSymbol{};



public:

    Instance(World *world, int hitPoints, int speed, int cost, int attackRange, int buildingTime, int posX, int posY);

    void setPosX(int posX);
    void setPosY(int posY);

    virtual void action() = 0;

    virtual void move() = 0;

    virtual char getSymbol();

    int getPosX() const;

    int getPosY() const;

    int getHitPoints();

    std::string getName();

    bool getMovePossible();

    void setMovePossible(bool status);

    // global inheritance for future creating building by base
    virtual int getBuildingCounter();
    virtual void setBuildingCounter(int buildingCounter);

    char getBaseSymbol() const;

    void setBaseSymbol(char symbol);

    int getSpeed() const;

    virtual ~Instance();
};

#endif
