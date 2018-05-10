//
// Created by student on 10.5.18.
//
#include "wolf.h"

using namespace std;

CWolf::CWolf ( pair<size_t, size_t> pos )
    :   CMonster ( pos, WOLF_HEALTH, WOLF_ATTACK, WOLF_SYMBOL )
{
}
CWolf::~CWolf()
{
}
