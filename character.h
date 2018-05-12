//
// Created by student on 10.5.18.
//

#ifndef SANDBOXGAME_CHARACTER_H
#define SANDBOXGAME_CHARACTER_H
#include <iostream>
#include <string>
#include <utility>
using namespace std;

/*
 * parent of all characters
 * holds the most impornant attributes ( health, attack )
 */
class CCharacter {
protected:
    char symbol;
    pair <size_t, size_t> position;
    int max_health;
    int health;
    int attack;
public:
    CCharacter ( pair<size_t, size_t> pos, int hea, int att, char sym );
    virtual ~CCharacter();
    char showChar () const { return symbol; }
    const char * printStats () const;
    void setHealth ( int hea );
    void setMaxHealth ( int maxHea );
    void setAttack ( int att );
    void setPosition ( size_t x, size_t y );
    pair <size_t, size_t> getPosition () const;
    bool correctPosition ( size_t x, size_t y) const;
    void recieveDmg ( int damage );
    void heal ( int health );
};

#endif //SANDBOXGAME_CHARACTER_H
