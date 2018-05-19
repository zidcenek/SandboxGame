//
// Created by student on 10.5.18.
//

#include "road.h"

CRoad::CRoad ()
{
}
CRoad::~CRoad ()
{
}
char CRoad::print () const {
    return ROAD_SYMBOL;
}
string CRoad::interact ( CCharacter * character ) const {
    if ( rand() % 10 <= 2 ){
        character -> heal ( 5 );
        return "While travelling on the road, your injurues have healed, recieve 5 health.\n";
    }
    return "You are travelling on the road safely.\n";
}