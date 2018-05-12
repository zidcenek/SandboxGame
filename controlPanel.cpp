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
            moves ( 0 ),
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
    map . load();
    cout << "How do you want to name your saved game?" << endl;
    string file;
    cin >> file;
    ofstream ofs ( file );
    map . save( ofs );
}
bool CControlPanel::readChar (){

}
