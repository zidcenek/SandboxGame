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

CCharacter::~CCharacter()
{
}
/**
 * setters
 */
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
/**
 * getters
 */
pair <size_t, size_t> CCharacter::getPosition () const{
    return position;
}

int CCharacter::getAttack() const {
    return attack;
}

char CCharacter::getSymbol() const {
    return symbol;
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

/**
 * shows stats actual after every movement
 * @return
 */
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

/**
 * interaction with another character
 * @param character - enemy character
 */
void CCharacter::interaction ( CCharacter * character ) {
    cast ( character );
    character -> cast( this );
}

/**
 * deals dmg to a self
 * @param damage - power of the attack
 */
void CCharacter::recieveDmg ( int damage ){
    health -= damage;
}

/**
 * heals for a certain amount of health
 * @param heal - power of the healing effect
 */
void CCharacter::heal( int heal ) {
    health += heal;
    if ( health > max_health )
        health = max_health;
}

/**
 * checks wheter character is still alive
 * @return - true if alive
 */
bool CCharacter::stillAlive (){
    return health > 0;
}