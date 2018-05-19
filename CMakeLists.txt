cmake_minimum_required(VERSION 3.10)
project(sandboxGame)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS "-Wall")

add_executable(sandboxGame main.cpp character.h character.cpp player.h player.cpp npc.h npc.cpp bear.h bear.cpp monster.h monster.cpp wolf.h wolf.cpp friend.h friend.cpp terrain.h terrain.cpp road.h road.cpp woods.h woods.cpp lava.h lava.cpp view.h view.cpp map.h map.cpp controlPanel.h controlPanel.cpp treasure.h treasure.cpp)