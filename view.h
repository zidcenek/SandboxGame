//
// Created by student on 11.5.18.
//

#ifndef SANDBOXGAME_VIEW_H
#define SANDBOXGAME_VIEW_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class CView {
protected:
    ostream & os;
public:
    CView ( ostream & ostr );
    ~CView();
    void print ( const char * str );
    void print ( char str );
};
#endif //SANDBOXGAME_VIEW_H