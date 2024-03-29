//
// Created by student on 10.5.18.
//

#ifndef SANDBOXGAME_PLAYER_H
#define SANDBOXGAME_PLAYER_H
#include "character.h"

const char PLAYER_SYMBOL = 'P';

/**
 * class representing Player ( user ) ( specific symbol P )
 */
class CPlayer : public CCharacter {
protected:
public:
    CPlayer ( pair<size_t, size_t> pos, int hea, int att );
    virtual bool stillAlive ();
    virtual void cast ( CCharacter * character );
};

#endif //SANDBOXGAME_PLAYER_H
