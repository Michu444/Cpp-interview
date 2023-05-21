#include <iostream>
#include <conio.h>
#include <windows.h>
#include "World.h"


/*
 * Basic constructor to create game world.
 */
World::World(int mapSizeX, int mapSizeY)
{
    this->mapSizeX = mapSizeX;
    this->mapSizeY = mapSizeY;
    this->maxMapSize = mapSizeX * mapSizeY;

    round = 0;
    numberOrganisms = 0;
    gameEnd = false;

    this->createMap();

    player_1 = new Base(this, 0, 0, '1');

//    player_2 = new Base(this, 11, 11, '2');

    this->setInstanceOnMap(player_1, 0, 0);

//    this->setInstanceOnMap(player_2, 11, 11);

}

/*
 * Destructor where map object is also deleting.
 */
World::~World()
{
    for (int x = 0; x < this->mapSizeX; ++x)
    {
        for (int y = 0; y < this->mapSizeY; ++y)
        {
            delete map[x][y];
        }
        delete[] map[x];
    }
    delete[] map;
}


/*
 * Main method responsible for all processes during single round.
 */
void World::makeRound()
{
    system("cls");


    if (round >= 2000 || player_1->getHitPoints() <= 0 && player_2->getHitPoints() <= 0) // TODO maybe add var if gameEnd == true do this too..
    {
        this->endGame();
        gameEnd = true;
    }

    this->increaseRound();
    std::cout << "\nRound: " << this->getRound() << "\n\n";


    for (int y = 0; y < this->mapSizeX; ++y)
    {
        for (int x = 0; x < this->mapSizeY; ++x)
        {

            if (auto *building = dynamic_cast<Building*>(map[x][y]))
            {
                this->handleBuilding(building);
                std::cout << "\nPRESS ENTER TO CONTINUE\n";
                getch();

            }
            else if (auto *character = dynamic_cast<Character*>(map[x][y]))
            {
                if (map[x][y]->getMovePossible())
                {
//                    this->handleCharacter(character);
                    std::cout << "\nPRESS ENTER TO CONTINUE\n";

                    getch();
                }
                else
                {
                    std::cout << "Unit: " << map[x][y]->getName() << " at position: (" << map[x][y]->getPosX()
                              << ", " << map[x][y]->getPosY() << ") cant move!\n";
                }

                continue;
            }
            else if (map[x][y] == nullptr)
            {
                continue;
            }
            else
            {
                throw std::logic_error("UNRECOGNIZED OBJECT ON THE MAP!");
                exit(1);
            }
        }
    }

    std::cout << "\nEND OF THE " << this->getRound() << " ROUND! PRESS ENTER TO GO TO NEXT ROUND!\n";
}


/*
 * Handle character instances in single round.
 *
 * @param character: Character object to handle.
 */
void World::handleCharacter(Character *character)
{
    while(true)
    {
        system("cls"); // TODO CHANGE ON LINUX COMMAND
        this->displayMap();
        std::cout << "\n---------------------";
        int choose;
        std::cout << "Character turn: " << character->getName() << " at position: (" << character->getPosX() << ", " << character->getPosY() << ")\n";
        std::cout << "[1] Move character" << "\n";
        std::cout << "[2] Make action!" << "\n";
        std::cout << "What do you want to do? ";
        choose = getch();
        std::cout << "\n\n";

        switch(choose)
        {
            case '1':
            {
               character->move();
               return;
            }
            case '2':
            {
                character->action();
                return;
            }
            default:
            {
                std::cout << "Wrong option! Try again." << "\n";
                break;
            }
        }
    }
}


/*
 * Handle building instances in single round.
 *
 * @param building: Object to handle.
 */
void World::handleBuilding(Building *building)
{
    if (Base *base = dynamic_cast<Base*>(building))
    {
        if (base->getStatusInProgress() && base->getBuildingCounter() > 0)
        {
            base->setBuildingCounter(base->getBuildingCounter() - 1);
        }
        else if ( base->getStatusInProgress() && base->getBuildingCounter() == 0)
        {
            this->numberOrganisms++;
            base->setNumberOfUnits(base->getNumberOfUnits() + 1);
            base->setStatusInProgress(false);
            // TODO ADD UNIT ON MAP - THINK ABOUT HOW TO ADD IT ON BASE FIELD
        }
        else if (!base->getStatusInProgress() && base->getBuildingCounter() == 0 && base->getCharacterInProgress())
        {
            std::cout << "You can move your new character from base!\n";

            base->getCharacterInProgress()->move();
        }
    }

    building->action();
}


/*
 * Place instance read from file. Checking if it is possible to place on the map. If unit exist on map field, unit
 * will not be placed.
 *
 * @param instance: Object which we need to place on map.
 */
void World::placeExistingCharacter(Instance* instance)
{
    if (numberOrganisms < maxMapSize && this->checkMapField(instance->getPosX(), instance->getPosY()))
    {
        this->map[instance->getPosX()][instance->getPosY()] = instance;
    }
}


/*
 * Creating new character in base object. Whether object will be created depends on the amount of the gold in player base.\
 * Checking also whether amount of object in map is not bigger than map size.
 *
 * @param base: player Base object
 */
void World::createCharacterInBase(Base *base)
{

    if (numberOrganisms < maxMapSize && !base->getStatusInProgress())
    {
        while(true)
        {
            int choose;

            std::cout << "[1] Knight" << "\n";
            std::cout << "[2] Skip round" << "\n";
            std::cout << "Which character do you want to create? ";
            choose = getch();
            std::cout << "\n";

            switch(choose)
            {
                case '1':
                {
                    if (base->getGold() >= 400)
                    {
                        Knight *knight = new Knight(this, base->getPosX(), base->getPosY());
                        this->setBaseDuringCrafting(base, knight, true, 400);
                        return;
                    }
                    else
                    {
                        std::cout << "\nYou dont have enough gold!" << "\n\n";
                    }

                }
                case '2':
                {
                    return;
                }
                default:
                {
                    std::cout << "Wrong option! Try again." << "\n";
                    break;
                }
            }
        }
    }
    else if (numberOrganisms < maxMapSize && base->getStatusInProgress())
    {
        base->getCharacterInProgress()->setBuildingCounter(base->getCharacterInProgress()->getBuildingCounter() - 1);
        std::cout << "Rounds to end " << base->getCharacterInProgress()->getName() << " creating: "
                  << base->getCharacterInProgress()->getBuildingCounter();
    }
    else
    {
        std::cout << "Map is full, you cant create new Object in base!" << "\n";
    }
}


/*
 * Removes Instance object from map, clear memory and decrement number of available in game instances. Method
 * using, for example, when character will be defeated by other unit.
 *
 * @param instance: Instance object to remove.
 *
 * @param posX: x coord of the object to remove.
 * @param posY: y coord of the object to remove.
 */
void World::removeInstanceFromGame(Instance *instance, int posX, int posY)
{
    this->map[posX][posY] = nullptr;
    delete instance;
    this->numberOrganisms--;
    // TODO add option to remove unit from base counters
}


/*
 * Set base status when user picked character to create.
 *
 * @param base: Player base object.
 * @param character: Character object chosen to craft.
 * @param status: Crafting status in base.
 * @param goldToSub: Number of gold to subtract from base gold.
 */
void World::setBaseDuringCrafting(Base* base, Instance *character, bool status, long int goldToSub)
{
    base->setCharacterInProgress(character);
    base->setStatusInProgress(status);
    base->setGold(base->getGold() - goldToSub);
    base->setBuildingCounter(character->getBuildingCounter());
}


/*
 * Setting object on map in given coords place.
 *
 * @param instance: Object to be placed on map.
 * @param posX: x coord where object will be placed on map.
 * @param posY: y coord where object will be placed on map.
 */
void World::setInstanceOnMap(Instance *instance, int posX, int posY)
{
    this->map[posX][posY] = instance;
}


/*
 * Get object located on given coords in map.
 *
 * @param x: x coord to check on map.
 * @param y: y coord to check on map.
 *
 * @return: Instance object - map position.
 */
Instance *World::getField(int x, int y)
{
    return this->map[x][y];
}


/*
 * Checking if given place on map are empty or not.
 *
 * @param posX: x coord of checking place.
 * @param posY: y coord of checking place.
 *
 * @return: boolean status.
 */
bool World::checkMapField(int posX, int posY)
{
    if (this->map[posX][posY] == nullptr)
    {
        return true;
    }
    return false;
}


int World::getRound()
{
    return this->round;
}


bool World::getGameStatus()
{
    return this->gameEnd;
}


void World::increaseRound()
{
    this->round++;
}

/*
 * Summarize game and make operations during ending game.
 */
void World::endGame()
{
    Base *winner;

    if (this->getRound() >= 2000 && player_1->getHitPoints() > 0 && player_2->getHitPoints() > 0)
    {
        if (player_1->getNumberOfUnits() > player_2->getNumberOfUnits())
        {
            winner = player_1;
        }
        else
        {
            winner = player_2;
        }
    }
    else if (player_1->getHitPoints() > player_2->getHitPoints())
    {
        winner = player_1;
    }
    else if (player_1->getHitPoints() < player_2->getHitPoints())
    {
        winner = player_2;
    }
    else
    {
        std::cout << "SOMETHING IS WRONG!" << "\n"; // TODO REMOVE
    }

    system("cls"); // TODO CHANGE IT

    std::cout << "----- GAME END! -----" << "\n";
    std::cout << "-----  WINNER   -----" << "\n";
    std::cout << "----- PLAYER " << winner->getSymbol() << "!! ----" << "\n";
    std::cout << "  CONGRATULATIONS!!! " << "\n";
    getch();
}


/*
 * Creating empty map at the beginning of the game.
 */
void World::createMap() // remember to delete all map objects
{

    this->map = new Instance **[this->mapSizeX];

    for (int x = 0; x < this->mapSizeX; x++)
    {
        this->map[x] = new Instance * [this->mapSizeY];
    }

    for (int x = 0; x < mapSizeX; x++)
    {
        for (int y = 0; y < mapSizeY; y++)
        {
            map[x][y] = nullptr;
        }
    }
}

void World::displayInstanceInfo(Instance *instance)
{
    if(Base *base = dynamic_cast<Base*>(instance))
    {
        std::cout << "\n---------------------";
        std::cout << "\nBase turn" << " at position: (" << base->getPosX() << ", " << base->getPosY() << ")\n";
        std::cout << "Gold: " << base->getGold() << "\n";
        std::cout << "Units: " << base->getNumberOfUnits() << "\n\n";

        if (base->getStatusInProgress())
        {
            std::cout << "Unit in progress: " << base->getCharacterInProgress()->getName() << "(rounds left: "
                      << base->getBuildingCounter() << ") \n\n";
        }

        std::cout << "[1] Skip this round" << "\n";

        if (!base->getStatusInProgress())
        {
            std::cout << "[2] Create new character" << "\n";
        }
    }
    else if (Character *character = dynamic_cast<Character*>(instance))
    {
        // TODO DISPLAY INFO CHARACTER - hp, and other
    }
    else
    {
        // TODO IDK WHAT TO DO
    }
}

/*
 * Displays a representation of the map object. Each cell contains object or empty field.
 */
void World::displayMap()
{
    system("cls");

    // display first index row
    for (int i = 0; i < mapSizeX; i++)
    {
        if (i == 0)
        {
            std::cout << "     " << i;
        }
        else if (i < 10)
        {
            std::cout << "    " << i;
        }
        else
        {
            std::cout << "   " << i;
        }
    }

    std::cout << "\n";

    // display rows
    for (int y = 0; y < mapSizeY; y++)
    {
        if (y < 10)
        {
            std::cout << y << "  ";
        }
        else
        {
            std::cout << y << " ";
        }

        for (int x = 0; x < mapSizeX; x++)
        {
            if (getField(x, y) == nullptr)
            {
                std::cout << "  0  ";
            }
            else
            {
                std::cout << "  " << getField(x,y)->getSymbol() << "  ";
            }
        }

        std::cout << "\n";
    }
}


/*
 * Displays menu in console.
 */
char World::displayMenu()
{
    char option;

    do
    {
//        system("clear"); // TODO CHANGE TO WORK ON LINUX
         system("cls");

        std::cout << "----- MAIN MENU -----" << "\n";
        std::cout << " N - Create new game " << "\n";
        std::cout << " L - Load game       " << "\n";
        std::cout << " I - Game info       " << "\n";
        std::cout << " Q - Quit game       " << "\n";

        std::cout << "\nChoose option: ";

        option = getch();
        option = toupper(option);

        if (option != 'N' && option != 'L' && option != 'Q' && option != 'I')
        {
            system("cls");
            std::cout << "\nInvalid option. Please try again.";
            Sleep(1000);
        }

    } while (option != 'N' && option != 'L' && option != 'Q' && option != 'I');

    return option;
}


/*
 * Displays info in stdout about game and the title and author.
 */
void World::displayGameInfo()
{
    system("cls");

    std::cout << "------ WAR GAME! ------" << "\n";
    std::cout << "-----------------------" << "\n\n";
    std::cout << "----- DESCRIPTION -----" << "\n";
    std::cout << "This game was created for interview. I was very excited during writing all this code. Thanks you for the ";
    std::cout << "opportunity to participate in recruitment process and I am sorry that I did not manage to finish the whole game ";
    std::cout << "but i will do it for myself. Unfortunately I did not have enough time to create this game with GUI too.";
    std::cout << "\n\n";
    std::cout << "------- AUTHOR --------" << "\n";
    std::cout << "    MICHAL DUDZIAK     " << "\n\n\n";

    std::cout << "Press enter to exit info: ";
    getch();
}