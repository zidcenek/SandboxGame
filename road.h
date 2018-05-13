//
// Created by student on 10.5.18.
//

#ifndef SANDBOXGAME_ROAD_H
#define SANDBOXGAME_ROAD_H

#include "terrain.h"

const char ROAD_SYMBOL = 'R';

/**
 * class representing terrain - road ( symbol R )
 */
class CRoad : public CTerrain {
protected:
public:
    CRoad ();
    ~CRoad ();
    virtual char print () const;
};

#endif //SANDBOXGAME_ROAD_H
