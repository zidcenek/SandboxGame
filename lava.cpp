//
// Created by student on 11.5.18.
//

#include <vector>
#include "lava.h"
#include "stone.h"
using namespace std;

CLava::CLava()
    : durability ( 5 ),
      movesCounter ( 0 )
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
/**
 * after 5 moves, change the terrain to stone
 * @return
 */
CTerrain * CLava::action (){
    if ( ++ movesCounter == durability )
        return new CStone;
    return nullptr;
}