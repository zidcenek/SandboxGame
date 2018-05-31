//
// Created by student on 19.5.18.
//
#include "treasure.h"

CTreasure::CTreasure()
{
}
CTreasure::~CTreasure()
{
}

/**
 * prints itself
 * @return
 */
char CTreasure::print () const {
    return TREASURE_SYMBOL;
}

/**
 * player wins after finding this
 * @param character - player
 * @return - message
 */
string CTreasure::interact( CCharacter * character ) const {
    return "Oooh, it's the treasure!\n";
}