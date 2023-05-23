#include "SettingsReader.h"

// CLASS IS NOT FULLY IMPLEMENTED


SettingsReader::SettingsReader()
{
    pathToMap = "../settings/map.txt";
    pathToOrders = "settings/orders.txt";
    pathToStatus = "settings/status.txt";
}


char** SettingsReader::readMap()
{
    std::ifstream mapFile(pathToMap);

    if (!mapFile)
    {
        std::cerr << "Problem with read map.txt file!\n";
        exit(1);
    }

    std::string line;
    char **map = nullptr;

    int rows = 0, columns = 0;

    while (std::getline(mapFile, line))
    {
        if (rows == 0)
        {
            columns = line.size();
            map = new char*[rows];
        }
        else if (line.size() != columns)
        {
            throw std::runtime_error("Invaild columns on file map!");
            exit(1);

        }

        map[rows] = new char[columns];

        for (size_t i = 0; i < columns; ++i)
        {
            map[rows][i] = line[i];
        }

        ++rows;
    }

    return map;
}