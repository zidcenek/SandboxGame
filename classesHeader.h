#ifndef SANDBOXGAME_CLASSESHEADER_H
#define SANDBOXGAME_CLASSESHEADER_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include "character.h"
#include "player.h"
#include "npc.h"
#include "monster.h"
#include "bear.h"
#include "wolf.h"
#include "terrain.h"
#include "road.h"

using namespace std;
/*
 * *************************************Character******************************************
 * */
/*
 * *************************************PLayer - character******************************************
 * */
/*
 * *************************************NPC - character******************************************
 * */
/*
 * *************************************Monster - NPC - character******************************************
 * */
/*
 * *************************************Wolf - monster - NPC - character******************************************
 * */
/*
 * *************************************Bear - monster - NPC - character******************************************
 * */
/*
 * *************************************Friend - NPC - character******************************************
 * */
/*
 * *************************************Terrain******************************************
 * */
/*
 * *************************************Road - terrain******************************************
 * */
/*
 * *************************************Woods - terrain******************************************
 * */
class CWoods : public CTerrain {
protected:
public:
    CWoods ();
};
/*
 * *************************************Lava - terrain******************************************
 * */
class CLava : public CTerrain {
protected:
public:
    CLava ();
};
/*
 * *************************************CMap******************************************
 * */
class CMap {
protected:
    size_t width;
    size_t height;
    int moves;
    vector <vector<CTerrain*> > terrain_map;
    vector <vector<CCharacter*> > characters_map;
public:
    CMap ()
        :   width ( 0 ),
            height ( 0 ){}

    bool readHeader ( ifstream & ifs );
    bool readContent ( ifstream & ifs );
    bool load ();
    void save ();
    bool addTerrain ( const char & terrain, size_t lineNumber );
    bool addCharacter ( const char & character, size_t lineNumber );
};
/*
 * *************************************ControlPanel******************************************
 * */
class CControlPanel {
protected:
    size_t width;
    size_t height;
    int moves;
    CMap map;
    vector <CCharacter*> characters;
public:
    CControlPanel ();
    bool readChar ();
    bool initialize ();
};

#endif //SANDBOXGAME_CLASSESHEADER_H
