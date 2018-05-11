//
// Created by student on 10.5.18.
//

#ifndef SANDBOXGAME_MONSTER_H
#define SANDBOXGAME_MONSTER_H

#include "npc.h"

using namespace std;

/*
 * parent of all enemy monsters
 */
class CMonster : public CNpc {
protected:
public:
    CMonster ( pair<size_t, size_t> pos, int hea, int att, const char & sym  );
    virtual ~CMonster();
};

#endif //SANDBOXGAME_MONSTER_H
