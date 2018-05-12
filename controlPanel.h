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

class CControlPanel {
protected:
    size_t width;
    size_t height;
    CMap map;
    vector <CCharacter*> characters;
    CView * view;
public:
    CControlPanel ( ostream & os );
    ~CControlPanel();
    bool readChar ();
    bool initialize ();
};

#endif //SANDBOXGAME_CONTROLPANEL_H
