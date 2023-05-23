#include "World.h"
#include "utils/SettingsReader.h"
#include <iostream>

/*
 * Main func of game.
 */
int main()
{
    char option;
    World *world = nullptr;

    // MAIN MENU LOOP
    do
    {
        option = World::displayMenu();

        if (option == 'N')
        {
            // init map size manually
            world = new World(12 , 12);

        }
//        else if (option == 'L') // NOT IMPLEMENTED
//        {
//            SettingsReader settingsReader;
//
//            world = new World(12,12);
//
//            char **map = settingsReader.readMap();
//
//            std::cout << map;
//
//
//        }
        else if (option == 'Q')
        {
            system("clear");
            std::cout << "GOOD BYE!";
            std::cin.get();
            exit(0);
        } else if (option == 'I')
        {
            World::displayGameInfo();
        } else
        {
            throw std::runtime_error("PROGRAM CRASHED! PLEASE RUN GAME AGAIN");
        }
    } while (option != 'N');

    world->displayMap();

    // MAIN GAME LOOP
    do
    {
        world->makeRound();

    } while (!world->getGameStatus());

    system("clear");
    std::cout << "---THANK YOU FOR GAME!---" << "\n";
    getchar();
    while (getchar() != '\n') {} // clearing buffor - replaces getch() logic from windows lib in getchar() func

    return 0;
}
