#include "Base.h"
#include "../World.h"

Base::Base(World* world, int posX, int posY, char symbol)
: Building(world, 200, 0, 0, 0, 0, posX, posY)
{
    this->symbol = symbol;
    this->gold = 2000;
    this->name = "Base";
    this->numberOfUnits = 0;
    this->characterInBase = nullptr;
}

void Base::action()
{
    while (true)
    {
        int choose;

        system("cls"); // TODO change on linux command
        world->displayMap();
        world->displayInstanceInfo(this);


        std::cout << "[1] Skip the turn" << "\n";

        if (!this->getStatusInProgress() && this->getCharacterInBase() == nullptr)
        {
            std::cout << "[2] Create new character" << "\n";
        }

        if (!this->getStatusInProgress() && this->getCharacterInBase() != nullptr)
        {
            std::cout << "[3] Move your character from base" << "\n";
        }

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
                    return;
                }
                else
                {
                    std::cout << "\nInvalid option! Please choose again.\n\n";
                    break;
                }
            }
            case '3':
            {
                if (this->getCharacterInBase() != nullptr)
                {
                    this->getCharacterInBase()->setMovePossible(false);
                    this->getCharacterInBase()->move();

                    if (Character *character = dynamic_cast<Character*>(this->getCharacterInBase()))
                    {
                        if (!character->getNewUnitStatus())
                        {
                            this->setCharacterInBase(nullptr);
                        }
                    }

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

Instance *Base::getCharacterInBase()
{
    return this->characterInBase;
}

void Base::setCharacterInBase(Instance *character)
{
    this->characterInBase = character;
}

bool Base::getStatusInProgress()
{
    return this->unitInProgress;
}

void Base::setStatusInProgress(bool status)
{
    this->unitInProgress = status;
}



