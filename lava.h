//
// Created by student on 11.5.18.
//

#ifndef SANDBOXGAME_LAVA_H
#define SANDBOXGAME_LAVA_H

#include "terrain.h"

const char LAVA_SYMBOL = 'L';

/*
 * Class representing lava ( specific symbol L )
 */
class CLava : public CTerrain {
protected:
public:
    CLava ();
    ~CLava ();
    virtual char print () const;
};

#endif //SANDBOXGAME_LAVA_H
