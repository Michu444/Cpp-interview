cmake_minimum_required(VERSION 3.24)
project(interview)

set(CMAKE_CXX_STANDARD 17)

add_executable(interview main.cpp characters/Knight.cpp characters/Knight.h Instance.cpp Instance.h World.cpp World.h buildings/Base.cpp buildings/Base.h buildings/Building.cpp buildings/Building.h characters/Character.cpp characters/Character.h buildings/GoldMine.cpp buildings/GoldMine.h utils/SettingsReader.cpp utils/SettingsReader.h buildings/Obstacle.cpp buildings/Obstacle.h utils/HeadersConnector.h characters/SwordsMan.cpp characters/SwordsMan.h)
