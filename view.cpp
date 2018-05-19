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
void CView::invalidKey () {
    cout << "You pressed an invalid key, please try again" << endl;
}
/**
 * will change to a template method
 * @param str
 */
void CView::print ( const char * str ) {
    cout << str;
}
void CView::print ( const char str ){
    cout << str;
}
void CView::print ( string str ) {
    cout << str;
}
/**
 * prints unable to save mistake
 */
void CView::unableToSave() {
    cout << "Mistake while saving the game. Try a different filename." << endl;
}
/**
 * prints to a specific file ( will change to a template method )
 * @param ofs
 * @param str
 * @return
 */
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
bool CView::print ( ofstream & ofs, string str ){
    if ( ! ofs . is_open() )
        return false;
    ofs << str;
    if (!ofs.good())
        return false;
    return true;
}
/**
 * shows the main menu
 */
void CView::showMenu() {
    cout << "[l] load game" << endl
         << "[q] quit" << endl;
}
/**
 * show possibilities while playing the game
 */
void CView::showPossibilities (){
    cout << "[m] main menu" << endl
         << "[u] save game" << endl
         << "[w] move up" << endl
         << "[s] move down" << endl
         << "[a] move left" << endl
         << "[d] move right" << endl;
}
/**
 * shows an error when player tries to move somewhere forbidden
 */
void CView::cannotMoveThere (){
    cout << "You cannot move there." << endl;
}