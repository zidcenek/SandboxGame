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
         << "[i] introduction and controls" << endl
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

void CView::lostTheGame () {
    cout << "-----------------------" << endl;
    cout << "You have lost the game." << endl;
    cout << "-----------------------" << endl;
}

void CView::victory() {
    cout << "-----------------------" << endl;
    cout << "Congratulations! You have found the treasure and won the game!" << endl;
    cout << "-----------------------" << endl;
    cout << "-----------------------" << endl;
    cout << "Further statistics:" << endl;
}

void CView::introduction() {
    cout << "Movement - w s a d" << endl;
    cout << "Characters:" << endl;
    cout << "   P - player" << endl;
    cout << "   B - bear (50 Health, 15 attack)" << endl;
    cout << "   W - wolf (25 Health, 5 attack)" << endl;
    cout << "   F - friend - heals you when you interact with him" << endl;
    cout << "Terrain:" << endl;
    cout << "   R - road - 20% chance to be healed on the road" << endl;
    cout << "   W - woods - 10% chance a branch falls on your head" << endl;
    cout << "   L - lava - deals 10 damage every turn you stand here" << endl;
    cout << "     - lava has a chance to spread to adjacent terrains" << endl;
    cout << "     - after 5 turns lava turns into stone" << endl;
    cout << "   S - stone - nothing special" << endl;
    cout << "   T - treasure - finds this and win the game" << endl;
}