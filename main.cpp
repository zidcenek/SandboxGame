#include "classesHeader.h"
using namespace std;
/*
 * *************************************ControlPanel******************************************
 * */
/**
 * constructor
 */
CControlPanel::CControlPanel ( ostream & os )
    :   width ( 0 ),
        height ( 0 ),
        moves ( 0 ),
        view ( CView ( os ) ),
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
/*
 * *************************************CMap******************************************
 * */
/**
 * loads the whole map
 * @return
 */
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

 /**
  * parses specific characters and creates objects if possible
  * @param terrain - character representing a specific type of terrain
  * @param lineNumber - what line is the program supposed to modify
  * @return - if there is an unknown type of character
  */
bool CMap::addTerrain ( const char & terrain, size_t lineNumber ) {
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

/**
 * parses specific characters and creates objects if possible
 * @param character - character representing a specific type of character
 * @param lineNumber - what line is the program supposed to modify
 * @return
 */
bool CMap::addCharacter ( const char & character, size_t lineNumber ) {
    CCharacter * tmp;
    pair<size_t, size_t> pos = make_pair( lineNumber, characters_map[lineNumber] . size() );
    switch ( character ){
        case 'P' : tmp = new CPlayer ( pos, 100, 5 );
            break;
        case 'F' : tmp = new CFriend ( pos );
            break;
        case 'B' : tmp = new CBear ( pos );
            break;
        case 'w' : tmp = new CWolf ( pos );
        default  :
            tmp = new CFriend ( pos );
    }
    characters_map[ lineNumber ] . push_back( tmp );
    return true;
}

/**
 * reads header of the file
 * @param ifs - ifstream
 * @return - false if not in the correct format
 */
bool CMap::readHeader ( ifstream & ifs ){
    string readStr;
    size_t sz;
    if ( ! ifs . is_open() ) {
        return false;
    }
    /* parsing header */
    if ( ( ! readLine ( ifs, readStr, width ) ) || readStr != "width:" )
        return false;
    if ( ( ! readLine ( ifs, readStr, height ) ) || readStr != "heigh:" )
        return false;
    if ( ( ! readLine ( ifs, readStr, moves ) ) || readStr != "moves:" )
        return false;
    return true;
}

/**
 * reads the contents of the map
 * @param ifs - ifstream
 * @return
 */
bool CMap::readContent ( ifstream & ifs ){
    view . print ( "reading content\n ");
    int linesRead = 0;
    string line;
    for ( size_t i = 0 ; i < height ; i++ ){
        getline ( ifs, line );
        cout << line << endl;
        cout << line . length () << endl;
        line . push_back( ' ' );
        if ( line . length() == 3 * width - 1 )
            return false;
        for ( size_t j = 0 ; j < width ; j += 3 ){
            if ( line[ j + 2 ] != ' ' )
                return false;
            /* creation of the map */
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
/**
 * parsing my type of format used when saving the game ( string(5 chars):size_t )
 * @param ifs - ifstream
 * @param name - return parameter specifing name of the line ( width, height etc. )
 * @param value - return parameter which saves the proper parameter
 * @return - false if not in a correct format
 */
bool CMap::readLine ( ifstream & ifs, string & name, size_t & value ) {
    string line;
    size_t sz;
    getline (ifs, line );
    name = line . substr ( 0, 6 );
    line . erase ( 0, 6 );
    value = stoi ( line, &sz );
    line . erase ( 0, sz );
    if ( line != "") // wheter there is any junk
        return false;
    return true;
}
void CMap::save (){

}
/**
 * constructor
 */
CMap::CMap ( CView ostr )
        :   width ( 0 ),
            height ( 0 ),
            moves ( 0 ),
            view ( ostr )
{
}
/**
 * destructor
 */
CMap::~CMap()
{
}
/*
 * *************************************main******************************************
 * */
int main() {
    cout << "Hello, my Sandbox Game!" << endl;
    CControlPanel controler ( cout );
    controler . initialize ();
    return 0;
}