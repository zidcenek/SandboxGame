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
/**
 * while interacting with another character, there is some chance on special attack
 */
void CWolf::specialAttack ( CCharacter * enemy ) {
    enemy -> recieveDmg( attack );
    health = max_health;
};