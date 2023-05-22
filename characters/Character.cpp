#include "Character.h"
#include "../World.h"

Character::Character(World* world, int hitPoints, int speed, int cost, int attackRange, int buildingTime, int posX, int posY)
:Instance(world, hitPoints, speed, cost, attackRange, buildingTime, posX, posY)
{}

int Character::getBuildingTime()
{
    return this->buildingTime;
}

bool Character::getNewUnitStatus()
{
    return this->newUnitStatus;
}

int Character::getAttackValue(const std::string &unitName) const
{
    return 0;
}

/*
 * Support action for characters
 */
void Character::action()
{
    int choose;
    Instance *chosenToAttack;

    while(true)
    {
        world->displayMap();
        std::cout << "\n---------------------\n";
        std::cout << "Possible Attack (use all action points!) \n\n";

        std::vector<Instance*> unitsAround =  world->displayInstancesAround(this);

        //display units
        int unitsCounter = 1;
        for (Instance* unit : unitsAround)
        {
            std::cout << "[" << unitsCounter << "] " << unit->getName() << " at (" << unit->getPosX() << ", " << unit->getPosY() << ")\n";
            unitsCounter++;
        }

        if (unitsCounter == 1)
        {
            std::cout << "There are no any characters to fight!" << "\n\n";
        }

        std::cout << "[" << unitsCounter << "] Skip round\n\n";

        std::cout << "What you want to do? ";
        choose = getchar();
        int chooseInt = choose - '0';


        if (chooseInt == unitsCounter)
        {
            return;
        }
        else if (chooseInt > 0 && chooseInt < unitsCounter)
        {
            chosenToAttack = unitsAround[chooseInt-1];
            world->attackUnit(this, chosenToAttack);
            return;
        }
        else
        {
            std::cout << "\nInvalid option! Please choose again.\n\n";
        }
    }
}


/*
 * Support move for characters
 */
void Character::move()
{
    bool up = false, down = false, left = false, right = false;

    int maxMapX = this->world->getMapSizeX() - 1;
    int maxMapY = this->world->getMapSizeY() - 1;

    if (maxMapX > 0 && maxMapY > 0)
    {

        // left up corner
        if (this->getPosX() == 0 && this->getPosY() == 0)
        {
            right = true;
            down = true;
        }
        // right up corner
        else if (this->getPosY() == 0 && this->getPosX() == maxMapX)
        {
            left = true;
            down = true;
        }
        // left down corner
        else if (this->getPosX() == 0 &&  this->getPosY() == maxMapY)
        {
            up = true;
            right = true;
        }
        // right down corner
        else if (this->getPosY() == maxMapY && this->getPosX() == maxMapX)
        {
            up = true;
            left = true;
        }
        else if ((this->getPosX() == 0 && this->getPosY() > 0) || (this->getPosY() == 0 && this->getPosX() > 0))
        {
            // near up X axis
            if (this->getPosX() > 0 && this->getPosX() < maxMapX && this->getPosY() == 0)
            {
                left = true;
                right = true;
                down = true;
            }
                // near down X axis
            else if (this->getPosX() > 0 && this->getPosX() < maxMapX && this->getPosY() == maxMapY)
            {
                left = true;
                right = true;
                up = true;
            }
                // near left Y axis
            else if (this->getPosY() > 0 && this->getPosY() < maxMapY && this->getPosX() == 0 )
            {
                up = true;
                down = true;
                right = true;
            }
                // near right Y axis
            else if (this->getPosY() > 0 && this->getPosY() < maxMapY && this->getPosX() == maxMapX )
            {
                up = true;
                down = true;
                left = true;
            }
        }
            // in the middle - min 1 unit from the X or Y axis
        else
        {
            left = true;
            right = true;
            down = true;
            up = true;
        }
    }


    char choose;
    bool correctChoose = false;
    int newX = this->getPosX();
    int newY = this->getPosY();

    while(!correctChoose)
    {
        world->displayMap();

        // print info after unavailable choose
        if (choose == 'W' || choose == 'S' || choose == 'A' || choose == 'D' || choose == 'Q') // TODO CHECK IF WORKING
        {
            std::cout << "\nYou cant move here! Try again!\n\n";
        }

        std::cout << "Possible move for " << this->getName() << " (current: (" << this->getPosX() << ", " << this->getPosY() << ")) \n";
        std::cout << "---------------\n\n";

        // check up possible position
        if (up && this->world->checkMapField(this, this->getPosX(),this->getPosY() - 1))
        {
            std::cout << "[W] UP: (" << this->getPosX() << ", " << this->getPosY() - 1 << ")\n";
        }
        else
        {
            up = false;
        }

        // check right possible position
        if (right && this->world->checkMapField(this, this->getPosX() + 1,this->getPosY()))
        {
            std::cout << "[D] RIGHT: (" << this->getPosX() + 1 << ", " << this->getPosY() << ")\n";
        }
        else
        {
            right = false;
        }

        // check down possible position
        if (down && this->world->checkMapField(this, this->getPosX(),this->getPosY() + 1))
        {
            std::cout << "[S] DOWN: (" << this->getPosX() << ", " << this->getPosY() + 1 << ")\n";
        }
        else
        {
            down = false;
        }

        // check left possible position
        if (left && this->world->checkMapField(this, this->getPosX() - 1,this->getPosY()))
        {
            std::cout << "[A] LEFT: (" << this->getPosX() - 1 << ", " << this->getPosY() << ")\n";
        }
        else
        {
            left = false;
        }

        std::cout << "[Q] Cancel move" << "\n";

        //checking if any position is possible
        if (!up && !right && !down && !left)
        {
            std::cout << "You cant move anywhere!";
            return;
        }

        std::cout << "Where you want to move? ";
        choose = getchar();
        if (isalpha(choose))
        {
            choose = toupper(choose);
        }
        while (getchar() != '\n') {}

       switch(choose)
       {
           case 'W':
           {
               if (up)
               {
                   newY = this->getPosY() - 1;
                   correctChoose = true;
               }
               break;
           }
           case 'D':
           {
               if (right)
               {
                   newX = this->getPosX() + 1;
                   correctChoose = true;
               }
               break;
           }
           case 'S':
           {
               if (down)
               {
                   newY= this->getPosY() + 1;
                   correctChoose = true;
               }
               break;
           }
           case 'A':
           {
               if (left)
               {
                   newX = this->getPosX() - 1;
                   correctChoose = true;
               }
               break;
           }
           case 'Q':
           {
               return;
           }
           default:
           {
               std::cout << "Invalid option! Try again.";
               break;
           }
       }
    }

    if (this->newUnitStatus)
    {
        this->newUnitStatus = false;
    }

    this->world->setInstanceOnMap(this, newX, newY);
}
