//
// Created by student on 11.5.18.
//

#include "view.h"

using namespace std;

CView::CView ( ostream & ostr )
    : os ( ostr )
{
}
CView::~CView()
{
}
void CView::print ( string str ) {
    os << str;
}
