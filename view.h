//
// Created by student on 11.5.18.
//

#ifndef SANDBOXGAME_VIEW_H
#define SANDBOXGAME_VIEW_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * takes care of showing and printing everythigh to a ostream ( ofstream )
 */
class CView {
protected:
    ostream & os;
public:
    CView ( ostream & ostr );
    ~CView();
    void unableToSave ();
    void invalidKey ();
    void showPossibilities ();
    void cannotMoveThere();
    void showMenu ();
    void lostTheGame ();
    void victory ();
    void print ( const char * str );
    void print ( string str );
    void print ( char str );
    bool print ( ofstream & ofs, const char * str );
    bool print ( ofstream & ofs, char str );
    bool print ( ofstream & ofs, string str );
};
#endif //SANDBOXGAME_VIEW_H
