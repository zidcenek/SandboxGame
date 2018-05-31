//
// Created by student on 10.5.18.
//

#ifndef SANDBOXGAME_TERRAIN_H
#define SANDBOXGAME_TERRAIN_H

#include <iostream>
#include <cstdlib>
#include "character.h"

/**
 * parent to all terrains
 * #name -> represents symbol used by specific types of terrain
 */
class CTerrain {
protected:
    char name;
public:
    CTerrain ();
    virtual ~CTerrain ();
    virtual char print () const = 0;
    virtual string interact ( CCharacter * character ) const = 0;
    virtual CTerrain * action ();
};


#endif //SANDBOXGAME_TERRAIN_H
