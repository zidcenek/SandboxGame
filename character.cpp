//
// Created by student on 10.5.18.
//
#include "character.h"

CCharacter::CCharacter( pair<size_t, size_t> pos, int hea, int att, char sym )
        :   position ( pos ),
            max_health ( hea ),
            health ( max_health ),
            attack ( att ),
            symbol ( sym ){}

CCharacter::~CCharacter()
{
}
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

