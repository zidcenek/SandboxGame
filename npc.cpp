//
// Created by student on 10.5.18.
//
#include "npc.h"

using namespace std;

CNpc::CNpc ( pair<size_t, size_t> pos, int hea, int att, const char & sym )
    :   CCharacter::CCharacter ( pos, hea, att, sym )
{
}
CNpc::~CNpc()
{
}
CCharacter * CNpc::stillAlive (){
    if ( health < 0 )
        return nullptr;
    return this;
}