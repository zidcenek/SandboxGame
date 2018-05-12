//
// Created by student on 11.5.18.
//

#ifndef SANDBOXGAME_WOODS_H
#define SANDBOXGAME_WOODS_H

#include "terrain.h"

const char WOODS_SYMBOL = 'W';

/*
 * Class representing forest ( specific symbol W )
 */
class CWoods : public CTerrain {
protected:
public:
    CWoods ();
    ~CWoods ();
    virtual char print () const;
};

#endif //SANDBOXGAME_WOODS_H
