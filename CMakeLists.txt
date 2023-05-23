cmake_minimum_required(VERSION 3.22)
project(interview)

set(CMAKE_CXX_STANDARD 17)

# path to /build folder
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

# creating /build folder if not exists
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR})

# set build as main compilation files folder
set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_BINARY_DIR})

add_executable(interview main.cpp characters/Knight.cpp characters/Knight.h Instance.cpp Instance.h
        World.cpp World.h buildings/Base.cpp buildings/Base.h buildings/Building.cpp buildings/Building.h
        characters/Character.cpp characters/Character.h buildings/GoldMine.cpp buildings/GoldMine.h utils/SettingsReader.cpp
        utils/SettingsReader.h buildings/Obstacle.cpp buildings/Obstacle.h utils/HeadersConnector.h characters/Swordsman.cpp
        characters/Swordsman.h characters/Worker.cpp characters/Worker.h characters/Archer.cpp characters/Archer.h characters/Pikeman.cpp
        characters/Pikeman.h characters/Ram.cpp characters/Ram.h characters/Catapult.cpp characters/Catapult.h)
