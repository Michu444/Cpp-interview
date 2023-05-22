#ifndef INTERVIEW_CHARACTER_H
#define INTERVIEW_CHARACTER_H
#include "../Instance.h"

class Character :public Instance
{
protected:
    bool newUnitStatus; // change on false if unit move after created

public:
    Character(World* world, int hitPoints, int speed, int cost, int attackRange, int buildingTime, int posX, int posY);

    int getAttackValue(const std::string& unitName) const override;

    void action() override;

    void move() override;

    int getBuildingTime();

    bool getNewUnitStatus();

};

#endif