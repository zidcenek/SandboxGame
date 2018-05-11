//
// Created by student on 10.5.18.
//

#ifndef SANDBOXGAME_TERRAIN_H
#define SANDBOXGAME_TERRAIN_H

/*
 * parent to all terrains
 * #name -> represents symbol used by specific types of terrain
 */
 class CTerrain {
protected:
    char name;
public:
    CTerrain ();
    virtual ~CTerrain ();
};


#endif //SANDBOXGAME_TERRAIN_H
