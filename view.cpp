//
// Created by student on 11.5.18.
//

#include "view.h"

using namespace std;

CView::CView ( ostream & ostr )
    : os ( cout )
{
}
CView::~CView()
{
}
void CView::print ( const char * str ) {
    cout << str;
}
void CView::print ( const char str ){
    cout << str;
}
void CView::unableToSave() {
    cout << "Mistake while saving the game. Try a different filename." << endl;
}

bool CView::print ( ofstream & ofs, const char * str ){
    if ( ! ofs . is_open() )
        return false;
    ofs << str;
    if (!ofs.good())
        return false;
    return true;
}
bool CView::print ( ofstream & ofs, char str ){
    if ( ! ofs . is_open() )
        return false;
    ofs << str;
    if (!ofs.good())
        return false;
    return true;
}
