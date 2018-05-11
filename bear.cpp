//
// Created by student on 10.5.18.
//

#include "bear.h"

CBear::CBear ( pair<size_t, size_t> pos )
    :   CMonster::CMonster ( pos, BEAR_HEALTH, BEAR_ATTACK, BEAR_SYMBOL )
{
    cout << "bear symbol " << BEAR_SYMBOL << endl;
}
CBear::~CBear()
{
}