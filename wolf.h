//
// Created by student on 10.5.18.
//

#ifndef SANDBOXGAME_WOLF_H
#define SANDBOXGAME_WOLF_H

#include "monster.h"

const int WOLF_HEALTH = 25;
const int WOLF_ATTACK = 8;
const char WOLF_SYMBOL = 'w';

class CWolf : public CMonster {
protected:
public:
    CWolf ( pair<size_t, size_t> pos );
    ~CWolf();
};


#endif //SANDBOXGAME_WOLF_H
