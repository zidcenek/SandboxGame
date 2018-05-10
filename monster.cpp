//
// Created by student on 10.5.18.
//
#include "monster.h"

CMonster::CMonster ( pair<size_t, size_t> pos, int hea, int att, const char & sym  )
        : CNpc::CNpc ( pos, hea, att, sym )
{
}
CMonster::~CMonster ()
{
}

