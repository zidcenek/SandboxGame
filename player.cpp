//
// Created by student on 10.5.18.
//
#include "player.h"

using namespace std;

CPlayer::CPlayer ( pair<size_t, size_t> pos, int hea, int att )
    :   CCharacter::CCharacter ( pos, hea, att, PLAYER_SYMBOL )
{
}