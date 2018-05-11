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
#include "friend.h"
#include "monster.h"
#include "bear.h"
#include "wolf.h"
#include "terrain.h"
#include "road.h"
#include "lava.h"
#include "woods.h"

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
/*
 * *************************************Lava - terrain******************************************
 * */

/*
 * *************************************CMap******************************************
 * */
class CMap {
protected:
    size_t width;
    size_t height;
    size_t moves;
    vector <vector<CTerrain*> > terrain_map;
    vector <vector<CCharacter*> > characters_map;
public:
    CMap ();
    ~CMap();

    bool readHeader ( ifstream & ifs );
    bool readContent ( ifstream & ifs );
    bool readLine ( ifstream & ifs, string & name, size_t & value );
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
    ~CControlPanel();
    bool readChar ();
    bool initialize ();
};

#endif //SANDBOXGAME_CLASSESHEADER_H
