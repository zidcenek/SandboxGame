//
// Created by student on 11.5.18.
//

#include "controlPanel.h"

using namespace std;
/**
 * constructor
 */
CControlPanel::CControlPanel ( ostream & os )
        :   width ( 0 ),
            height ( 0 ),
            view ( new CView ( cout ) ),
            map ( view )
{
}
/**
 * destructor
 */
CControlPanel::~CControlPanel()
{
}
bool CControlPanel::initialize (){
    char pressedKey;
    bool play = false;
    //map . save ();
    cin . clear ();
    while ( true ){
        view -> showMenu();
        cin >> pressedKey;
        if ( pressedKey == 'q' )
            break;
        if ( pressedKey == 'l' ){
            while ( ! map . load () ){}
            play = true;
        }
        while ( play ){
            cin . clear ();
            view -> print ( map . printMap() );
            view -> print ( map . showCounter() );
            view -> showPossibilities();
            cin >> pressedKey;
            switch ( pressedKey ){
                case 'w' : map . move ( -1, 0 );
                break;
                case 's' : map . move ( 1, 0 );
                break;
                case 'a' : map . move ( 0, -1 );
                break;
                case 'd' : map . move ( 0, 1 );
                break;
                case 'u' : map . save ();
                break;
                case 'm' : play = false;
                break;
                default  :
                    view -> invalidKey ();
            }
        }
        }
}
bool CControlPanel::readChar (){

}
