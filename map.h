//
// Created by student on 11.5.18.
//

#ifndef SANDBOXGAME_MAP_H
#define SANDBOXGAME_MAP_H

#include "terrain.h"
#include "view.h"
#include <vector>

using namespace std;

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
    const char * printHeader ();
    bool load ();
    void save ( ofstream & ofs );
    bool addTerrain ( const char & terrain, size_t lineNumber );
    bool addCharacter ( const char & character, size_t lineNumber );
};

#endif //SANDBOXGAME_MAP_H
