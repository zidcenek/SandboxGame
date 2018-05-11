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
    map . save();
}
bool CControlPanel::readChar (){

}
