//
// Created by student on 11.5.18.
//

#include "lava.h"
using namespace std;

CLava::CLava()
{
}
CLava::~CLava()
{
}
char CLava::print () const {
    return LAVA_SYMBOL;
}
/**
 * deals damage to a character that stands on this terrain
 */
string CLava::interact ( CCharacter * character ) const {
    character -> recieveDmg( 10 );
    return "Lava burned you, you have recieved 10 damage.\n";
}