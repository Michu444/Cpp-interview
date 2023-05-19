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

    round = 0;
    numberOrganisms = 0;
    gameEnd = false;

    this->createMap();

    Base *player_1 = new Base(this, 0, 0, '1');

    Base *player_2 = new Base(this, 11, 11, '2');

    this->setInstanceOnMap(player_1, 0, 0);

    this->setInstanceOnMap(player_2, 11, 11);

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

    if (round == 2000) // TODO maybe add var if gameEnd == true do this too..
    {
        cout << "END GAME!\n";
        // this->endGame();
        gameEnd = true;
        return;
    }

    this->increaseRound();
    cout << "Round: " << this->getRound() << "\n\n";


    for (int y = 0; y < this->mapSizeX; ++y)
    {
        for (int x = 0; x < this->mapSizeY; ++x)
        {
            if (auto *building = dynamic_cast<Building*>(map[x][y]))
            {
                this->handleBuilding(building);

                cout << "FOUND BASE OBJECT!\n";

            }else if (auto *character = dynamic_cast<Character*>(map[x][y]))
            {
                cout << "FOUND CHARACTER OBJECT!\n";
                this->handleCharacter(character);

            }else if (map[x][y] == nullptr)
            {
                continue;
            }
            else
            {
                throw logic_error("UNRECOGNIZED OBJECT ON THE MAP!");
            }
        }
    }
}


/*
 * Creating instance read from file. Checking if it is possible to place on the map. If unit exist on map field, unit
 * will not be placed.
 *
 * @param instance: Object which we need to place on map.
 */
void World::createExistingCharacter(Instance* instance)
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
    int option;

    if (numberOrganisms < maxMapSize)
    {
        while(true)
        {
            cout << "[1] Knight" << "\n";
            cout << "[2] Cancel" << "\n";
            cout << "Which character do you want to create: ";
            cin >> option;

            if (option == 1 && base->getGold() >= 400 )
            {
                auto *knight = new Knight(this, base->getPosX(), base->getPosY());
                this->setBaseDuringCrafting(base, knight, true, 400);
                this->numberOrganisms++;
            }
            else if (option == 2)
            {
                return;
            }
            else
            {
                cout << "Wrong option or you don't have enough gold! Try again.";
            }
        }
    }
    else
    {
        cout << "Map is full, you cant create new Object in base!" << "\n";
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
}


/*
 * Set base status when user picked character to create.
 *
 * @param base: Player base object.
 * @param character: Character object chosen to craft.
 * @param status: Crafting status in base.
 * @param goldToSub: Number of gold to subtract from base gold.
 */
void World::setBaseDuringCrafting(Base* base, Instance *character, bool status, int goldToSub)
{
    base->setCharacterInProgress(character);
    base->setUnitInProgress(status);
    base->setGold(base->getGold()- goldToSub);
}


/*
 * Handle character instances in single round.
 *
 * @param character: Object to handle.
 */
void World::handleCharacter(Character *character)
{
    if (Knight *knight = dynamic_cast<Knight*>(character))
    {
        // TODO ...
    }
    else
    {
        return;
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
        base->action();
    }else
    {
        return;
    }
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


/*
 * Displays a representation of the map object. Each cell contains object or empty field.
 */
void World::displayMap()
{
    // display first index row
    for (int i = 0; i < mapSizeX; i++)
    {
        if (i == 0)
        {
            cout << "     " << i;
        }
        else if (i < 10)
        {
            cout << "    " << i;
        }
        else
        {
            cout << "   " << i;
        }
    }

    cout << "\n";

    // display rows
    for (int y = 0; y < mapSizeY; y++)
    {
        if (y < 10)
        {
            cout << y << "  ";
        }
        else
        {
            cout << y << " ";
        }

        for (int x = 0; x < mapSizeX; x++)
        {
            if (getField(x, y) == nullptr)
            {
                cout << "  0  ";
            }
            else
            {
                cout << "  " << getField(x,y)->getSymbol() << "  ";
            }
        }

        cout << endl;
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

        cout << "----- MAIN MENU -----" << "\n";
        cout << " N - Create new game " << "\n";
        cout << " L - Load game       " << "\n";
        cout << " I - Game info       " << "\n";
        cout << " Q - Quit game       " << "\n";

        cout << "\nChoose option: ";

        option = getch();
        option = toupper(option);

        if (option != 'N' && option != 'L' && option != 'Q' && option != 'I')
        {
            system("cls");
            cout << "\nInvalid option. Please try again.";
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

    cout << "------ WAR GAME! ------" << "\n";
    cout << "-----------------------" << "\n\n";
    cout << "----- DESCRIPTION -----" << "\n";
    cout << "This game was created for interview. I was very excited during writing all this code. Thanks you for the ";
    cout << "opportunity to participate in recruitment process and I am sorry that I did not manage to finish the whole game ";
    cout << "but i will do it for myself. Unfortunately I did not have enough time to create this game with GUI too.";
    cout << "\n\n";
    cout << "------- AUTHOR --------" << "\n";
    cout << "    MICHAL DUDZIAK     " << "\n\n\n";

    cout << "Press enter to exit info: ";
    getch();
}