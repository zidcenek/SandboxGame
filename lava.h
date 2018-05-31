//
// Created by student on 11.5.18.
//

#ifndef SANDBOXGAME_LAVA_H
#define SANDBOXGAME_LAVA_H

#include "terrain.h"

const char LAVA_SYMBOL = 'l';

/**
 * Class representing lava ( specific symbol l )
 */
class CLava : public CTerrain {
protected:
    int durability;
    int movesCounter;
public:
    CLava ();
    ~CLava ();
    virtual char print () const;
    virtual string interact ( CCharacter * character ) const;
    virtual CTerrain * action ();
};

#endif //SANDBOXGAME_LAVA_H
