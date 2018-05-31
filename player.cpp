//
// Created by student on 10.5.18.
//
#include "player.h"

using namespace std;

CPlayer::CPlayer ( pair<size_t, size_t> pos, int hea, int att )
    :   CCharacter::CCharacter ( pos, hea, att, PLAYER_SYMBOL )
{
}
/**
 * checks wheter player is still alive
 * @return - true if alive
 */
bool CPlayer::stillAlive (){
    return health > 0;
}

/**
 * player attacks its damage to an another character
 * @param character - another character
 */
void CPlayer::cast ( CCharacter * character ) {
    character -> recieveDmg ( getAttack() );
}
