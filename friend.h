//
// Created by student on 10.5.18.
//

#ifndef SANDBOXGAME_FRIEND_H
#define SANDBOXGAME_FRIEND_H

#include "character.h"

const int FRIEND_HEALTH = 100;
const int FRIEND_ATTACK = 5;
const char FRIEND_SYMBOL = 'F';
/**
 * class representing friendly NPC characters ( healer ) ( symbol F )
 */
class CFriend : public CCharacter {
protected:
public:
    CFriend ( pair<size_t, size_t> pos );
    ~CFriend();
    virtual void cast ( CCharacter * character );
    void talk () const;
};


#endif //SANDBOXGAME_FRIEND_H
