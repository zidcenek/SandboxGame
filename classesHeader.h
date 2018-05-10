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
using namespace std;

const int BEAR_HEALTH = 50;
const int BEAR_ATTACK = 15;
const char BEAR_SYMBOL = 'b';
const int WOLF_HEALTH = 25;
const int WOLF_ATTACK = 8;
const char WOLF_SYMBOL = 'w';
const int FRIEND_HEALTH = 100;
const int FRIEND_ATTACK = 5;
const char friend_SYMBOL = 'f';
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
class CMonster : public CNpc {
protected:
public:
    CMonster ( pair<size_t, size_t> pos, int hea, int att, const char & sym  )
            :   CNpc ( pos, hea, att, sym ){}
};
/*
 * *************************************Wolf - monster - NPC - character******************************************
 * */
class CWolf : public CMonster {
protected:
public:
    CWolf ( pair<size_t, size_t> pos )
            :   CMonster ( pos, BEAR_HEALTH, BEAR_ATTACK, BEAR_SYMBOL ){}
};
/*
 * *************************************Bear - monster - NPC - character******************************************
 * */
class CBear : public CMonster {
protected:
public:
    CBear ( pair<size_t, size_t> pos )
            :   CMonster ( pos, WOLF_HEALTH, WOLF_ATTACK, WOLF_SYMBOL ){}
};
/*
 * *************************************Friend - NPC - character******************************************
 * */
class CFriend : public CNpc {
protected:
public:
    CFriend ( pair<size_t, size_t> pos );
};
/*
 * *************************************Terrain******************************************
 * */
class CTerrain {
protected:
    char name;
public:
    CTerrain ();
};
/*
 * *************************************Road - terrain******************************************
 * */
class CRoad : public CTerrain {
protected:
public:
    CRoad ();
};
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
