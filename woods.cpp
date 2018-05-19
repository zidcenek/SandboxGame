//
// Created by student on 11.5.18.
//

#include "woods.h"


CWoods::CWoods()
{
}
CWoods::~CWoods()
{
}
char CWoods::print () const {
    return WOODS_SYMBOL;
}
/**
 * there is a chance a branch falls on the player's head and stuns him for one turn ( add 1 move )
 */
string CWoods::interact ( CCharacter * character ) const {
    if ( rand() % 10 <= 1 ) {
        character->recieveDmg( 5 );
        return "A log has fallen on your head, you have been injured and you have recieved 5 damage.\n";
    }
    return "Nothing happend to you in the woods.\n";
}