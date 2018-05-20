//
// Created by student on 10.5.18.
//

#include "friend.h"

using namespace std;

CFriend::CFriend ( pair<size_t, size_t> pos )
        : CNpc::CNpc ( pos, FRIEND_HEALTH, FRIEND_ATTACK, FRIEND_SYMBOL )
{
}
CFriend::~CFriend()
{
}
void CFriend::interaction ( CCharacter * character ){
    character -> heal ( 10 );
}