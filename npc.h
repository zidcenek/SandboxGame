//
// Created by student on 10.5.18.
//

#ifndef SANDBOXGAME_NPC_H
#define SANDBOXGAME_NPC_H
#include "character.h"

using namespace std;

class CNpc : public CCharacter {
protected:
public:
    CNpc ( pair<size_t, size_t> pos, int hea, int att, const char & sym );
    virtual ~CNpc();
    //virtual void interact ();
};

#endif //SANDBOXGAME_NPC_H
