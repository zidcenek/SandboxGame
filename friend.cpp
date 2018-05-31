//
// Created by student on 10.5.18.
//

#include "friend.h"

using namespace std;

CFriend::CFriend ( pair<size_t, size_t> pos )
        : CCharacter::CCharacter ( pos, FRIEND_HEALTH, FRIEND_ATTACK, FRIEND_SYMBOL )
{
}
CFriend::~CFriend()
{
}

/**
 * method defining how is this character supposed to interact with another - heals
 * @param character - another character
 */
void CFriend::cast ( CCharacter * character ){
    character -> heal ( 10 );
    health = max_health;
}