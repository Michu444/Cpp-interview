#ifndef INTERVIEW_BASE_H
#define INTERVIEW_BASE_H
#include "Building.h"

class Base : public Building
{
protected:
    char symbol;
    int gold;
    World *world;

    Instance *characterInProgress;
    bool unitInProgress;

public:
    Base(World* world, int posX, int posY, char symbol);

    void action() override;

    char getSymbol() override;

    int getGold();

    void setGold(int goldToSet);

    Instance *getCharacterInProgress();

    void setCharacterInProgress(Instance *character);

    bool getUnitInProgress();

    void setUnitInProgress(bool status);

};

#endif