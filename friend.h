//
// Created by student on 10.5.18.
//

#ifndef SANDBOXGAME_FRIEND_H
#define SANDBOXGAME_FRIEND_H

#include "npc.h"

const int FRIEND_HEALTH = 100;
const int FRIEND_ATTACK = 5;
const char FRIEND_SYMBOL = 'f';
/*
 * class representing friendly NPC characters ( merchant, guard ... )
 */
class CFriend : public CNpc {
protected:
public:
    CFriend ( pair<size_t, size_t> pos );
    ~CFriend();
};


#endif //SANDBOXGAME_FRIEND_H
