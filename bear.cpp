//
// Created by student on 10.5.18.
//

#include "bear.h"

CBear::CBear ( pair<size_t, size_t> pos )
    :   CMonster::CMonster ( pos, BEAR_HEALTH, BEAR_ATTACK, BEAR_SYMBOL )
{
}
CBear::~CBear()
{
}
/**
 * while interacting with another character, there is some chance on special attack
 * @return
 */
void CBear::specialAttack ( CCharacter * enemy ) {
    enemy -> recieveDmg( attack );
}