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
/**
 * prints itself
 * @return
 */
char CStone::print () const {
    return STONE_SYMBOL;
}

/**
 * stone does not effect the character
 * @param character - interacting character
 * @return - message
 */
string CStone::interact( CCharacter * character ) const {
    return "Stones does not effect you.\n";
}