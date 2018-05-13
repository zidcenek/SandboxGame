//
// Created by student on 10.5.18.
//

#ifndef SANDBOXGAME_WOLF_H
#define SANDBOXGAME_WOLF_H

#include "monster.h"

const int WOLF_HEALTH = 25;
const int WOLF_ATTACK = 8;
const char WOLF_SYMBOL = 'w';

/**
 * class representing specific monster - bear ( symbol B )
 */
class CWolf : public CMonster {
protected:
public:
    CWolf ( pair<size_t, size_t> pos );
    ~CWolf();
    virtual void specialAttack () const;
};


#endif //SANDBOXGAME_WOLF_H
