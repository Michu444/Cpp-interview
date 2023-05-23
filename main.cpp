#include "World.h"
#include "utils/SettingsReader.h"
#include <iostream>

//void signalHandler(int signum) {
//    endwin();
//    exit(signum);
//}

int main()
{
    char option;
    World *world = nullptr;
    int mapSizeX, mapSizeY;

//    initscr(); // initialize ncurses
//    cbreak();  // buffor line off
//    noecho();  // chars show off
//
//    signal(SIGINT, signalHandler); // signal handle: Ctrl+C
//    signal(SIGTERM, signalHandler); // term signal handle


    // MAIN MENU LOOP
    do
    {
        option = World::displayMenu();

        if (option == 'N')
        {
            std::cout << "Type size x and size y of the map: ";
            std::cin >> mapSizeX >> mapSizeY;

            world = new World(mapSizeX, mapSizeY);

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
