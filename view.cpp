//
// Created by student on 11.5.18.
//

#include "view.h"

using namespace std;

CView::CView ( ostream & ostr )
    : os ( cout )
{
    os << "sracka" << endl;
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