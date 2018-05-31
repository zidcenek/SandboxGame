//
// Created by student on 11.5.18.
//

#ifndef SANDBOXGAME_CONTROLPANEL_H
#define SANDBOXGAME_CONTROLPANEL_H

#include <map>
#include <vector>
#include "character.h"
#include "map.h"
#include "view.h"
using namespace std;
/**
 * takes care about playing the game
 */
class CControlPanel {
protected:
    CView * view;
    CMap map;
public:
    CControlPanel ( CView * v );
    ~CControlPanel();
    void initialize ();
    void playMove ( bool & play );
};

#endif //SANDBOXGAME_CONTROLPANEL_H
