#ifndef INTERVIEW_BASE_H
#define INTERVIEW_BASE_H
#include "Building.h"

class GoldMine : public Building
{
public:
    GoldMine(World* world, int pos_x, int pos_y);

    void action() override;

    void move() override;
};

#endif