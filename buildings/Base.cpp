#include "Base.h"
#include "../World.h"

Base::Base(World* world, int posX, int posY, char symbol)
: Building(world, 200, 0, 0, 0, 0, posX, posY)
{
    this->symbol = symbol;
    this->world = world;
    this->gold = 2000;
    name = "Base";
}

void Base::action()
{
    int choose;

    while (true)
    {
        std::cout << "[1] Skip this round" << "\n";

        if (!unitInProgress)
        {
            std::cout << "[2] Create new character" << "\n";
        }

        std::cout << "What you want do to: ";
        std::cin >> choose;

        switch (choose)
        {
            case 1:
            {
                return;
            }
            case 2:
            {
                if (!unitInProgress)
                {
                    this->world->createCharacterInBase(this);
                    return;
                }
                else
                {
                    std::cout << "\nInvalid option. Please choose again.\n\n";
                }

            }
            default:
            {
                std::cout << "\nInvalid option. Please choose again.\n\n";
            }
        }
    }



}

char Base::getSymbol()
{
    return this->symbol;
}

int Base::getGold()
{
    return this->gold;
}

void Base::setGold(int goldToSet)
{
    this->gold = goldToSet;
}

Instance *Base::getCharacterInProgress()
{
    return this->characterInProgress;
}

void Base::setCharacterInProgress(Instance *character)
{
    this->characterInProgress = character;
}

bool Base::getUnitInProgress()
{
    return this->unitInProgress;
}

void Base::setUnitInProgress(bool status)
{
    this->unitInProgress = status;
}



