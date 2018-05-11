CXX=g++
LD=g++
CXXFLAGS=-std=c++11

all: psfit

psfit: main.o bear.o friend.o lava.o npc.o road.o view.o woods.o character.o monster.o player.o terrain.o wolf.o
	$(LD) -o $@ $^

clean:
	rm -f bear.o friend.o lava.o npc.o road.o view.o woods.o character.o monster.o player.o terrain.o wolf.o

%o: %cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

bear.o: bear.cpp bear.h monster.h npc.h character.h
friend.o: friend.cpp friend.h npc.h character.h
character.o: character.cpp character.h
lava.o: lava.cpp lava.h terrain.h
main.o: main.cpp character.h player.h npc.h friend.h \
 monster.h bear.h wolf.h terrain.h road.h lava.h woods.h view.h
monster.o: monster.cpp monster.h npc.h character.h
npc.o: npc.cpp npc.h character.h
player.o: player.cpp player.h character.h
road.o: road.cpp road.h terrain.h
terrain.o: terrain.cpp terrain.h
view.o: view.cpp view.h
wolf.o: wolf.cpp wolf.h monster.h npc.h character.h
woods.o: woods.cpp woods.h terrain.h

