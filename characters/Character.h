#ifndef INTERVIEW_CHARACTER_H
#define INTERVIEW_CHARACTER_H
#include "../Instance.h"

class Character :public Instance
{
protected:

    bool movePossible{};
    int buildingCounter{};
    char symbol{};

public:
    Character(World* world, int hitPoints, int speed, int cost, int attack_range, int building_time, int posX, int posY);

    void action() override;

    void move() override;

    char getSymbol() override;

    int getPosX() override;
    int getPosY() override;

};

#endif