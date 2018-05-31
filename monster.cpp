//
// Created by student on 10.5.18.
//
#include "monster.h"
#include <cstdlib>

CMonster::CMonster ( pair<size_t, size_t> pos, int hea, int att, const char & sym  )
        : CCharacter::CCharacter ( pos, hea, att, sym )
{
}
CMonster::~CMonster ()
{
}

/**
 * monster attacks to a certain character
 * @param character - enemy
 */
void CMonster::cast ( CCharacter * character ){
    character -> recieveDmg ( getAttack() );
    if ( rand() % 10 < 1 )
        specialAttack( character );
}

