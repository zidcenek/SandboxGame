#include "classesHeader.h"
using namespace std;
/*
 * *************************************ControlPanel******************************************
 * */

CControlPanel::CControlPanel ()
    :   width ( 0 ),
        height ( 0 ),
        moves ( 0 ){}

bool CControlPanel::initialize (){
    map . load();
}
bool CControlPanel::readChar (){

}
/*
 * *************************************CMap******************************************
 * */
bool CMap::load (){
    string srcFile;

    cout << "Enter file name, you want to load" << endl;
    if ( ! ( cin >> srcFile ) )
        cout << "wrong name" << endl;
    ifstream ifs ( srcFile, ios::in );
    if ( ifs . fail () ) {
        cout << "Unable to read the file" << endl;
        return false;
    }
    if ( ! readHeader( ifs ) ){
        cout << "Unable to read header" << endl;
        return false;
    }
    if ( ! readContent( ifs ) ){
        cout << "Unable to read content" << endl;
        return false;
    }
}
bool CMap::addTerrain ( const char & terrain, size_t lineNumber )
{
    CTerrain * tmp;
    switch ( terrain ){
        case 'L' : tmp = new CLava ();
        break;
        case 'R' : tmp = new CRoad ();
        break;
        case 'W' : tmp = new CWoods ();
        break;
        default  :
            return false;
    }
    terrain_map[ lineNumber ] . push_back( tmp );
    return true;
}
bool CMap::addCharacter ( const char & character, size_t lineNumber )
{
    /*switch ( character ){
        case 'W' :
    }*/
    return true;
}
bool CMap::readHeader ( ifstream & ifs ){
    string readStr;
    size_t sz;
    if ( ! ifs . is_open() ) {
        return false;
    }
    /* parsing header */
    getline (ifs, readStr ); // width
    if ( readStr . substr ( 0, 6 ) != "width:" )
        return false;
    readStr . erase ( 0, 6 );
    width = stoi ( readStr, &sz );
    readStr . erase ( 0, sz );
    if ( readStr != "") // wheter there is any junk
        return false;

    getline (ifs, readStr ); // height
    if ( readStr . substr ( 0, 7 ) != "height:" )
        return false;
    readStr . erase ( 0, 7 );
    height = stoi ( readStr, &sz );
    readStr . erase ( 0, sz );
    if ( readStr != "") // wheter there is any junk
        return false;

    getline (ifs, readStr ); // moves
    if ( readStr . substr ( 0, 6 ) != "moves:" )
        return false;
    readStr . erase ( 0, 6 );
    moves = stoi ( readStr, &sz );
    readStr . erase ( 0, sz );
    if ( readStr != "") // wheter there is any junk
        return false;
    return true;
}
bool CMap::readContent ( ifstream & ifs ){
    cout << "reading content" << endl;
    int linesRead = 0;
    string line;
    for ( size_t i = 0 ; i < height ; i++ ){
        getline ( ifs, line );
        cout << line << endl;
        cout << line . length () << endl;
        line . push_back( ' ' );
        if ( line . length() < 3 * width )
            return false;
        for ( size_t j = 0 ; j < width ; j += 3 ){
            if ( line[ j + 2 ] != ' ' )
                return false;
            vector <CTerrain*> new_terrain_vector;
            vector <CCharacter*> new_character_vector;
            terrain_map . push_back( new_terrain_vector );
            characters_map . push_back( new_character_vector );
            if ( ! addTerrain ( line[ j ], i  ) ){
                cout << "Wrong terrain index" << endl;
                return false;
            }
            if ( ! addCharacter ( line [ j ], i ) ){
                cout << "Wrong character index" << endl;
                return false;
            }
        }
    }
    return true;
}
void CMap::save (){

}
/*
 * *************************************CTerrain******************************************
 * */
CTerrain::CTerrain() {};
/*
 * *************************************CLava******************************************
 * */
CLava::CLava() {}
/*
 * *************************************CRoad******************************************
 * */
CRoad::CRoad() {}
/*
 * *************************************CWoods******************************************
 * */
CWoods::CWoods() {}
/*
 * *************************************CCharacter******************************************
 * */
CCharacter::CCharacter( pair<size_t, size_t> pos, int hea, int att, char sym )
        :   position ( pos ),
            max_health ( hea ),
            health ( max_health ),
            attack ( att ),
            symbol ( sym ){}
/*
 * *************************************CWoods******************************************
 * */
/*CNpc::CNpc( pair<size_t, size_t> pos, int hea, int att )
        :   CCharacter::CCharacter( pos, hea, att ) {}*/
/*
 * *************************************CWoods******************************************
 * */
//CFriend::CFriend( pair<size_t, size_t> pos )
//        : CNpc ( pos, 100, 5 ) {}
/*
 * *************************************CWoods******************************************
 * */
/*
 * *************************************CWoods******************************************
 * */
/*
 * *************************************CWoods******************************************
 * */

/*
 * *************************************main******************************************
 * */
int main() {
    cout << "Hello, my Sandbox Game!" << endl;
    CControlPanel controler;
    controler . initialize ();
    return 0;
}