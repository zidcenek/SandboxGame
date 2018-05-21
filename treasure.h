//
// Created by student on 19.5.18.
//

#ifndef SANDBOXGAME_TREASURE_H
#define SANDBOXGAME_TREASURE_H

#include "terrain.h"

const char TREASURE_SYMBOL = 't';

/**
 * if you stand here you win the game
 */
class CTreasure : public CTerrain {
protected:
public:
    CTreasure ();
    ~CTreasure ();
    virtual char print () const;
    virtual string interact ( CCharacter * character ) const;
};

#endif //SANDBOXGAME_TREASURE_H
