//
// Created by student on 5.5.18.
//

#ifndef SANDBOXGAME_CLASSESHEADER_H
#define SANDBOXGAME_CLASSESHEADER_H
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <memory>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;


/*
 * *************************************Character******************************************
 * */
class CCharacter {
protected:
    char name;
    pair <size_t, size_t> position;
    int max_health;
    int health;
    int attack;
public:
    CCharacter ( pair<size_t, size_t> pos, int hea, int att );
    char showChar () const { return name; }
    void setPosition ( size_t x, size_t y );
    pair <size_t, size_t> getPosition () const;
    bool correctPosition ( size_t x, size_t y) const;
    void recieveDmg ( int damage );
    void heal ( int health );
};
/*
 * *************************************PLayer - character******************************************
 * */
class CPlayer : public CCharacter {
protected:
public:
    CPlayer ( pair<size_t, size_t> pos, int hea, int att );
};
/*
 * *************************************NPC - character******************************************
 * */

class CNpc : public CCharacter {
protected:
public:
    CNpc ( pair<size_t, size_t> pos, int hea, int att );
    virtual void interact ();
};
/*
 * *************************************Monster - NPC - character******************************************
 * */
class CMonster : public CNpc {
protected:
public:
    CMonster ( pair<size_t, size_t> pos );
};
/*
 * *************************************Wolf - monster - NPC - character******************************************
 * */
class CWolf : public CMonster {
protected:
public:
    CWolf ( pair<size_t, size_t> pos );
};
/*
 * *************************************Bear - monster - NPC - character******************************************
 * */
class CBear : public CMonster {
protected:
public:
    CBear ( pair<size_t, size_t> pos );
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
 * *************************************ControlPanel******************************************
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
