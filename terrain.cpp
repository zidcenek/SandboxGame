//
// Created by student on 10.5.18.
//

#include "terrain.h"

using namespace std;

CTerrain::CTerrain ()
{
}
CTerrain::~CTerrain ()
{
}
/**
 * iteract will not do anything unless explicitly defined
 */
string CTerrain::interact( CCharacter * character ) const
{
}
/**
 * represents action that happens every moce with the terrain
 * does nothing unless explicitly defined
 */
CTerrain * CTerrain::action()
{
    return nullptr;
}