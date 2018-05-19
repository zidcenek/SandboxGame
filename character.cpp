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
string CCharacter::printStats () const{
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
    return out;
}
void CCharacter::setHealth ( int hea ){
    health = hea;
}
void CCharacter::setMaxHealth ( int maxHea ){
    max_health = maxHea;
}
void CCharacter::setAttack ( int att ){
    attack = att;
}
void CCharacter::setPosition(size_t x, size_t y) {
    position . first = x;
    position . second = y;
}
pair <size_t, size_t> CCharacter::getPosition () const{
    return position;
};
string CCharacter::showStats() const {
    string out;
    out . append ( "Health: ");
    out . append( to_string( health ) ) . append ( " / " );
    out . append( to_string( max_health ) );
    out . append( "\nAttack: " );
    out . append( to_string( attack ) );
    out . append( "\n" );
    return out;
}

void CCharacter::interaction ( CCharacter * attacker ) {
    recieveDmg ( attacker -> getAttack() );
    attacker -> recieveDmg ( getAttack() );
}
void CCharacter::recieveDmg ( int damage ){
    health -= damage;
}

int CCharacter::getMax_health() const {
    return max_health;
}

int CCharacter::getHealth() const {
    return health;
}

int CCharacter::getAttack() const {
    return attack;
}
void CCharacter::heal( int heal ) {
    health += heal;
    if ( health > max_health )
        health = max_health;
}

char CCharacter::getSymbol() const {
    return symbol;
}
