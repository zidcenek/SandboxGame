CXX=g++
LD=g++
CXXFLAGS=-std=c++11

all: sandboxGame

sandboxGame: main.o bear.o friend.o lava.o road.o view.o woods.o character.o monster.o player.o terrain.o wolf.o controlPanel.o map.o treasure.o
	$(LD) -o $@ $^

clean:
	rm -f bear.o friend.o lava.o npc.o road.o view.o woods.o character.o monster.o player.o terrain.o wolf.o controlPanel.o map.o main.o sandboxGame

%o: %cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

bear.o: bear.cpp bear.h monster.h character.h
controlPanel.o: controlPanel.cpp controlPanel.h character.h map.h terrain.h view.h
friend.o: friend.cpp friend.h character.h
character.o: character.cpp character.h
lava.o: lava.cpp lava.h terrain.h character.h
main.o: main.cpp character.h player.h npc.h friend.h monster.h bear.h wolf.h terrain.h road.h lava.h woods.h view.h map.h controlPanel.h
map.o: map.cpp character.h map.h terrain.h view.h friend.h bear.h monster.h wolf.h player.h lava.h woods.h road.h treasure.h
monster.o: monster.cpp monster.h character.h
player.o: player.cpp player.h character.h
road.o: road.cpp road.h terrain.h character.h
terrain.o: terrain.cpp terrain.h character.h
treasure.o: treasure.cpp treasure.h terrain.h character.h
view.o: view.cpp view.h
wolf.o: wolf.cpp wolf.h monster.h character.h
woods.o: woods.cpp woods.h terrain.h character.h



