//
// Created by student on 11.5.18.
//

#ifndef SANDBOXGAME_MAP_H
#define SANDBOXGAME_MAP_H

#include "terrain.h"
#include "view.h"
#include <vector>

using namespace std;
/**
 * represents map, holds all the character and terrain info
 */
class CMap {
protected:
    size_t width;
    size_t height;
    size_t moves;
    vector <vector<CTerrain*> > terrain_map;
    vector <vector<CCharacter*> > characters_map;
    vector <CCharacter*> characters;
    CView * view;
public:
    CMap ( CView * myview );
    ~CMap();
    bool readHeader ( ifstream & ifs );
    bool readContent ( ifstream & ifs );
    bool readLine ( ifstream & ifs, string & name, size_t & value );
    bool readCharacterInfo ( ifstream & ifs );
    string printHeader ();
    bool load ();
    void save ();
    bool addTerrain ( const char & terrain, size_t lineNumber );
    bool addCharacter ( const char & character, size_t lineNumber );
    bool correctPosition ( size_t x, size_t y );
    void move ( size_t x, size_t y );
    string printMap ();
    void increasesMoves ();
    void decreaseMoves ();
    string showCounter();
    void clean ();
    bool loseTheGame ();
    CCharacter * getPlayer () const;
    void terrainInteraction () const;
};

#endif //SANDBOXGAME_MAP_H
