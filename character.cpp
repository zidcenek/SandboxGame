//
// Created by student on 10.5.18.
//
#include "character.h"
/**
 * should always recieve parametrs from its children
 * @param pos - position
 * @param hea - health
 * @param att - attack
 * @param sym - symbol ( one character )
 */
CCharacter::CCharacter( pair<size_t, size_t> pos, int hea, int att, char sym )
        :   position ( pos ),
            max_health ( hea ),
            health ( max_health ),
            attack ( att ),
            symbol ( sym ){}
/**
 * destructor
 */
CCharacter::~CCharacter()
{
}
/**
 * prints stats of a single character - used when saving the game
 * @return
 */
const char * CCharacter::printStats () const{
    string out;
    out . append ( "posiX:" );
    out . append ( to_string( position . first ) );
    out . append( "\n" );
    out . append ( "posiY:" );
    out . append ( to_string( position . second ) );
    out . append( "\n" );
    out . append ( "healt:" );
    out . append ( to_string( health ) );
    out . append( "\n" );
    out . append ( "attac:" );
    out . append ( to_string( attack ) );
    out . append( "\n" );
    out . append ( "mxhea:" );
    out . append ( to_string( max_health ) );
    out . append( "\n" );
    return out . c_str();
}
void CCharacter::setHealth ( int hea ){
    health = hea;
}
void CCharacter::setMaxHealth ( int maxHea ){
    health = maxHea;
}
void CCharacter::setAttack ( int att ){
    health = att;
}
void CCharacter::setPosition(size_t x, size_t y) {
    position . first = x;
    position . second = y;
}
pair <size_t, size_t> CCharacter::getPosition () const{
    return position;
};