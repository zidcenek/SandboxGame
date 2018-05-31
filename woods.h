//
// Created by student on 11.5.18.
//

#ifndef SANDBOXGAME_WOODS_H
#define SANDBOXGAME_WOODS_H

#include "terrain.h"

const char WOODS_SYMBOL = 'w';

/**
 * Class representing forest ( specific symbol w )
 */
class CWoods : public CTerrain {
protected:
public:
    CWoods ();
    ~CWoods ();
    virtual char print () const;
    virtual string interact ( CCharacter * character ) const;
};

#endif //SANDBOXGAME_WOODS_H
