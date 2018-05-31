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
    size_t max_moves;
    vector <vector<CTerrain*> > terrain_map;
    vector <vector<CCharacter*> > characters_map;
    vector <CCharacter*> characters;
    CView * view;
public:
    CMap ( CView & myview );
    ~CMap();
    bool readHeader ( ifstream & ifs );
    bool readContent ( ifstream & ifs );
    bool readLine ( ifstream & ifs, string & name, size_t & value );
    bool readCharacterInfo ( ifstream & ifs );
    string printHeader () const;
    string printMap () const;
    string showCounter() const;
    bool load ();
    void save () const;
    void clean ();
    bool addTerrain ( const char & terrain, size_t lineNumber );
    bool addCharacter ( const char & character, size_t lineNumber );
    bool correctPosition ( size_t x, size_t y ) const;
    void move ( int x, int y );
    void increasesMoves ();
    bool loseTheGame () const;
    bool winTheGame () const;
    CCharacter * getPlayer () const;
    void terrainInteraction () const;
    void terrainEvent ();
    void lavaSpreading ();
    void terrainChange ();
    bool isAdjacentLava ( size_t x, size_t y ) const;
};

#endif //SANDBOXGAME_MAP_H
