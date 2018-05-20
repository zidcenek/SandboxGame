//
// Created by student on 20.5.18.
//

#ifndef SANDBOXGAME_STONE_H
#define SANDBOXGAME_STONE_H

#include "terrain.h"

const char STONE_SYMBOL = 'S';

/**
 * neutral terrain
 */
class CStone : public CTerrain {
protected:
public:
    CStone ();
    ~CStone ();
    virtual char print () const;
    virtual string interact ( CCharacter * character ) const;
};

#endif //SANDBOXGAME_STONE_H
