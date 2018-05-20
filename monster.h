//
// Created by student on 10.5.18.
//

#ifndef SANDBOXGAME_MONSTER_H
#define SANDBOXGAME_MONSTER_H

#include "character.h"

using namespace std;

/**
 * parent of all enemy monsters
 */
class CMonster : public CCharacter {
protected:
public:
    CMonster ( pair<size_t, size_t> pos, int hea, int att, const char & sym  );
    virtual ~CMonster();
    virtual void cast ( CCharacter * character );
    virtual void specialAttack ( CCharacter * enemy ) = 0;
};

#endif //SANDBOXGAME_MONSTER_H
