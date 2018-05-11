//
// Created by student on 10.5.18.
//

#ifndef SANDBOXGAME_BEAR_H
#define SANDBOXGAME_BEAR_H

#include "monster.h"

using namespace std;

const int BEAR_HEALTH = 50;
const int BEAR_ATTACK = 15;
const char BEAR_SYMBOL = 'B';

/*
 * class representing specific monster - bear ( symbol B )
 */
class CBear : public CMonster {
protected:
public:
    CBear ( pair<size_t, size_t> pos );
    ~CBear();
};


#endif //SANDBOXGAME_BEAR_H
