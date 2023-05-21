#include "Base.h"
#include "../World.h"

Base::Base(World* world, int posX, int posY, char symbol)
: Building(world, 200, 0, 0, 0, 0, posX, posY)
{
    this->symbol = symbol;
    this->world = world;
    this->gold = 2000;
    name = "Base";
    numberOfUnits = 0;
}

void Base::action()
{
    while (true)
    {
        int choose;

        system("cls"); // TODO change on linux command
        world->displayMap();
        world->displayInstanceInfo(this);

        std::cout << "What do you want to do? ";
        choose = getch();
        std::cout << "\n\n";

        switch (choose)
        {
            case '1':
            {
                return;
            }
            case '2':
            {
                if (!unitInProgress)
                {
                    this->world->createCharacterInBase(this);
                    std::cout << "Started creating: " << this->getCharacterInProgress()->getName() << "\n";
                    std::cout << "Rounds to create: " << this->getCharacterInProgress()->getBuildingCounter() << "\n";
                    return;
                }
                else
                {
                    std::cout << "\nInvalid option! Please choose again.\n\n";
                    break;
                }
            }
            default:
            {
                std::cout << "\nInvalid option! Please choose again.\n\n";
                break;
            }
        }
    }
}

char Base::getSymbol()
{
    return this->symbol;
}

long int Base::getGold()
{
    return this->gold;
}

void Base::setGold(long int goldToSet)
{
    this->gold = goldToSet;
}

int Base::getNumberOfUnits()
{
    return this->numberOfUnits;
}

void Base::setNumberOfUnits(int numberOfUnits)
{
    this->numberOfUnits = numberOfUnits;
}

Instance *Base::getCharacterInProgress()
{
    return this->characterInProgress;
}

void Base::setCharacterInProgress(Instance *character)
{
    this->characterInProgress = character;
}

bool Base::getStatusInProgress()
{
    return this->unitInProgress;
}

void Base::setStatusInProgress(bool status)
{
    this->unitInProgress = status;
}



