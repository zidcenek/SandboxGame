//
// Created by student on 10.5.18.
//

#ifndef SANDBOXGAME_WOLF_H
#define SANDBOXGAME_WOLF_H

#include "monster.h"

const int WOLF_HEALTH = 25;
const int WOLF_ATTACK = 8;
const char WOLF_SYMBOL = 'W';

/**
 * class representing specific monster - wolf ( symbol W )
 */
class CWolf : public CMonster {
protected:
public:
    CWolf ( pair<size_t, size_t> pos );
    ~CWolf();
    virtual void specialAttack ( CCharacter * enemy );
};


#endif //SANDBOXGAME_WOLF_H
