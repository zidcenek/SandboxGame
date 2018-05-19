//
// Created by student on 10.5.18.
//

#ifndef SANDBOXGAME_NPC_H
#define SANDBOXGAME_NPC_H
#include "character.h"

using namespace std;

/**
 * parent of non player characters ( friendly and enemy characters )
 */
class CNpc : public CCharacter {
protected:
public:
    CNpc ( pair<size_t, size_t> pos, int hea, int att, const char & sym );
    virtual ~CNpc();
    virtual CCharacter * stillAlive ();
    //virtual void interact ();
};

#endif //SANDBOXGAME_NPC_H
