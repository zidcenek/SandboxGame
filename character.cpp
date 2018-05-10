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