//
// Created by student on 11.5.18.
//

#include "controlPanel.h"

using namespace std;

CControlPanel::CControlPanel ( CView * v )
        :   view ( v ),
            map ( *v )
{
}

CControlPanel::~CControlPanel()
{
}

/**
 * initializes player's gaming experience ( shows main menu, etc )
 * @return
 */
void CControlPanel::initialize (){
    char pressedKey;
    bool play = false;
    cin . clear ();
    while ( true ){
        view -> showMenu();
        cin >> pressedKey;
        view -> clear();
        switch ( pressedKey ){
            case 'q' :
                break;
            case 'l' : while ( ! map . load () ){}
                play = true;
                break;
            case 'i' :
                view -> introduction ();
                break;
            default : view -> invalidKey ();
        }
        if ( pressedKey == 'q' ) {
            break;
        }
        while ( play ){
            playMove ( play );
        }
        map . clean();
    }
    cin . clear ();
}

/**
 * used for actual playing - is in endless cycle until the game ends or is ended
 * @param play - wheter game is still to be played
 */
void CControlPanel::playMove ( bool & play ){
    char pressedKey;
    cin . clear ();
    view -> print ( map . printMap() );
    view -> print ( map . showCounter() );
    view -> print ( map . getPlayer() -> showStats () );
    view -> showPossibilities();
    cin >> pressedKey;
    view -> clear ();
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
        default  : view -> invalidKey ();
    }
    /* In case of victory */
    if ( map . winTheGame() ){
        view -> victory ();
        view -> print ( map . printMap() );
        view -> print ( map . showCounter() );
        view -> print ( map . getPlayer() -> showStats () );
        view -> print ( "-----------------------\n" );
        play = false;
    }
    /* In case of defeat */
    if ( map . loseTheGame () ) {
        view -> lostTheGame ();
        play = false;
    }
}
