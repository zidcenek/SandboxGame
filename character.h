//
// Created by student on 10.5.18.
//

#ifndef SANDBOXGAME_CHARACTER_H
#define SANDBOXGAME_CHARACTER_H
#include <iostream>
#include <string>
#include <utility>
using namespace std;

/**
 * parent of all characters
 * holds the most important attributes ( health, attack )
 */
class CCharacter {
protected:
    pair <size_t, size_t> position;
    int max_health;
    int health;
    int attack;
    char symbol;
public:
    int getAttack() const;
    char getSymbol() const;
    void setHealth ( int hea );
    void setMaxHealth ( int maxHea );
    void setAttack ( int att );
    CCharacter ( pair<size_t, size_t> pos, int hea, int att, char sym );
    virtual ~CCharacter();
    char showChar () const { return symbol; }
    string printStats () const;
    pair <size_t, size_t> getPosition () const;
    void setPosition ( size_t x, size_t y );
    virtual string showStats () const;
    virtual void cast ( CCharacter * character ) = 0;
    void interaction ( CCharacter * character );
    virtual bool stillAlive ();
    void recieveDmg ( int damage );
    void heal ( int heal );
};

#endif //SANDBOXGAME_CHARACTER_H
