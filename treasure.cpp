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
char CTreasure::print () const {
    return TREASURE_SYMBOL;
}
string CTreasure::interact(CCharacter *character) const {
    return "Oooh, it's the treasure!\n";
}