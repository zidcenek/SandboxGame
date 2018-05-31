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

/**
 * clears the console
 */
void CView::clear() {
    for ( int i = 0 ; i < 20 ; i ++)
        os << endl;
}

/**
 * invalid key message
 */
void CView::invalidKey () {
    os << "You pressed an invalid key, please try again" << endl;
}

/**
 * prints a const char
 * @param str
 */
void CView::print ( const char * str ) {
    os << str;
}

/**
 * prints string
 * @param str
 */
void CView::print ( const char str ){
    os << str;
}

/**
 * prints a string
 * @param str
 */
void CView::print ( string str ) {
    os << str;
}

/**
 * prints unable to save mistake
 */
void CView::unableToSave() {
    os << "Mistake while saving the game. Try a different filename." << endl;
}

/**
 * prints to a specific file a const char
 * @param ofs - certain file
 * @param str - message
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

/**
 * prints to a specific file a character
 * @param ofs - certain file
 * @param str - message
 * @return
 */
bool CView::print ( ofstream & ofs, char str ){
    if ( ! ofs . is_open() )
        return false;
    ofs << str;
    if (!ofs.good())
        return false;
    return true;
}

/**
 * prints to a specific file a string
 * @param ofs - certain file
 * @param str - message
 * @return
 */
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
    os << "[l] load game" << endl
         << "[i] introduction and controls" << endl
         << "[q] quit" << endl;
}

/**
 * shows possibilities while playing the game
 */
void CView::showPossibilities (){
    os << "[m] main menu" << endl
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
    os << "You cannot move there." << endl;
}

/**
 * comment when the game is lost
 */
void CView::lostTheGame () {
    os << "-----------------------" << endl;
    os << "You have lost the game." << endl;
    os << "-----------------------" << endl;
}

/**
 * comment when the game is won
 */
void CView::victory() {
    os << "-----------------------" << endl;
    os << "Congratulations! You have found the treasure and won the game!" << endl;
    os << "-----------------------" << endl;
    os << "-----------------------" << endl;
    os << "Further statistics:" << endl;
}

/**
 * introduction to controls and game itself
 */
void CView::introduction() {
    os << "Movement - w s a d" << endl;
    os << "Characters (all Characters are represented with upper case chars):" << endl;
    os << "   P - player" << endl;
    os << "   B - bear (50 Health, 15 attack)" << endl;
    os << "     - 10% chance to special attack (deal double damage) " << endl;
    os << "   W - wolf (25 Health, 5 attack)" << endl;
    os << "     - 10% chance to special attack (heal self to max health) " << endl;
    os << "   F - friend - heals you when you interact with him" << endl;
    os << "Terrain (all types of terrain are represented with lower case chars):" << endl;
    os << "   r - road - 20% chance to be healed on the road" << endl;
    os << "   w - woods - 10% chance a branch falls on your head" << endl;
    os << "   l - lava - deals 10 damage every turn you stand here" << endl;
    os << "     - lava has a chance to spread to adjacent terrains" << endl;
    os << "     - after 5 turns lava turns into stone" << endl;
    os << "   s - stone - nothing special" << endl;
    os << "   t - treasure - finds this and win the game" << endl;
}