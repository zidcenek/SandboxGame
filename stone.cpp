//
// Created by student on 20.5.18.
//

#include "stone.h"

CStone::CStone()
{
}
CStone::~CStone()
{
}
char CStone::print () const {
    return STONE_SYMBOL;
}
string CStone::interact( CCharacter *character ) const {
    return "Oooh, it's the treasure!\n";
}