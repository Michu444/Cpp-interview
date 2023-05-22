#include "World.h"
#include "utils/SettingsReader.h"
#include <iostream>

int main()
{
    char option;
    World *world = nullptr;

    // MAIN MENU LOOP
    do // TODO CHANGE ON SWITCH WITH GETCH
    {
//        option = World::displayMenu(); //TODO UNCOMMENT
        option = 'N';

        if (option == 'N')
        {
            world = new World(12, 12);

        } else if (option == 'L')
        {
            SettingsReader settingsReader;

            world = new World(12,12); // TODO

            char **map = settingsReader.readMap();

            std::cout << map;

            // TODO second constructor to prepare world with setted settings where settings are converted to correct data.
            // World world(map, orders, status); <-- inside all should be converted to correct vaules.

        } else if (option == 'Q')
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
            exit(1);
        }
    } while (option != 'N' && option != 'L');

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
