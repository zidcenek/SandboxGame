//
// Created by student on 11.5.18.
//

#include <vector>
#include <string>
#include <sstream>

#include "character.h"
#include "map.h"
#include "friend.h"
#include "bear.h"
#include "wolf.h"
#include "player.h"
#include "terrain.h"
#include "lava.h"
#include "woods.h"
#include "road.h"


/**
 * constructor
 */
CMap::CMap ( CView * myview )
        :   width ( 0 ),
            height ( 0 ),
            moves ( 0 ),
            view ( view )
{
}

/**
 * destructor
 */
CMap::~CMap()
{
    for ( auto i = terrain_map . begin () ; i != terrain_map . end () ; ++ i )
        for ( auto j = i -> begin () ; j != i -> end () ; ++ j )
            delete *j;
    for ( auto i = characters . begin () ; i != characters . end () ; ++i )
        delete *i;
}

/**
 * loads the whole map
 * @return
 */
bool CMap::load (){
    string srcFile;

    cout << "Enter file name, you want to load" << endl;
    if ( ! ( cin >> srcFile ) )
        view -> print ( "wrong file name\n" );
    ifstream ifs ( srcFile, ios::in );
    if ( ifs . fail () ) {
        view -> print ( "Unable to read the file\n" );
        return false;
    }
    if ( ! readHeader( ifs ) ){
        view -> print ( "Unable to read header\n" );
        return false;
    }
    if ( ! readContent( ifs ) ){
        view -> print ( "Unable to read content" );
        return false;
    }
    if ( ! readCharacterInfo( ifs ) ){
        view -> print ( "Unable to read character info" );
        return false;
    }
    return true;
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
            break;
        case '_' : tmp = nullptr;
            break;
        default  :
            return false;
    }
    if ( tmp != nullptr )
        characters . push_back( tmp );
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
    view -> print ( "reading content\n" );
    int linesRead = 0;
    string line;
    int counter = 0;
    for ( size_t i = 0 ; i < height ; i++ ){
        getline ( ifs, line );
        line . push_back( ' ' );
        if ( line . length() == 3 * width - 1 )
            return false;
        for ( size_t j = 0 ; j < 3 * width ; j += 3 ){
            if ( line[ j + 2 ] != ' ' )
                return false;
            /* creation of the map */
            vector <CTerrain*> new_terrain_vector;
            vector <CCharacter*> new_character_vector;
            terrain_map . push_back( new_terrain_vector );
            characters_map . push_back( new_character_vector );
            counter ++;
            if ( ! addTerrain ( line[ j ], i  ) ){
                view -> print ( "Wrong terrain index\n" );
                return false;
            }
            if ( ! addCharacter ( line [ j + 1 ], i ) ){
                cout << "Wrong character index\n" << endl;
                return false;
            }
        }
    }
    cout << "counter " << counter << endl;
    return true;
}
/**
 * reads special character info such as health, attack, etc. ( used while loading a saved game )
 * @param ifs
 * @return
 */
bool CMap::readCharacterInfo ( ifstream & ifs ) {
    view -> print ( "readingCharacterInfo\n" );
    string line;
    size_t value;
    size_t coordX;
    size_t coordY;
    int counter = 0;
    while ( getline ( ifs, line ) . good () ){
        if ( ifs . eof () )
            break;
        if  ( line != "" )
            return false;
        if ( ( ! readLine ( ifs, line, coordX ) ) || line != "posiX:" )
            return false;
        if ( ( ! readLine ( ifs, line, coordY ) ) || line != "posiY:" )
            return false;
        if ( characters_map[ coordX ][ coordY ] == nullptr )
            return false;
        if ( ( ! readLine ( ifs, line, value ) ) || line != "healt:" )
            return false;
        characters_map[ coordX ][ coordY ] -> setHealth ( (int) value );
        if ( ( ! readLine ( ifs, line, value ) ) || line != "attac:" )
            return false;
        characters_map[ coordX ][ coordY ] -> setAttack ( (int) value );
        if ( ( ! readLine ( ifs, line, value ) ) || line != "mxhea:" )
            return false;
        characters_map[ coordX ][ coordY ] -> setMaxHealth ( (int) value );

    }
    return  true;
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
    try {
        value = (unsigned)stoi(line, &sz);
    }catch ( exception e ){
        return false;
    }
    line . erase ( 0, sz );
    if ( line != "") // wheter there is any junk
        return false;
    return true;
}

/**
 * prints a header of the map required for saving the game
 * @return - returns a string that can be further printed to file / console...
 */
string CMap::printHeader (){
    string out;
    out . append ( "width:" );
    out . append ( to_string( width ) );
    out . append ( "\n" );
    out . append ( "heigh:" );
    out . append ( to_string( height ) );
    out . append ( "\n" );
    out . append ( "moves:" );
    out . append ( to_string( moves ) );
    out . append ( "\n" );
    return out;
}

/**
 * saves the game into the relevant file
 * also checks wheter the mofification of the output file went well
 * @param ofs - file where the game will be saved
 */
void CMap::save (){
    cout << "How do you want to name your saved game?" << endl;
    string file;
    cin >> file;
    ofstream ofs ( file );

    if ( ! view -> print ( ofs, printHeader() ) ) {
        view ->unableToSave();
        return;
    }
    if ( ! view -> print ( ofs, printMap() ) ){
        view -> unableToSave();
        return;
    }
    for ( auto i = characters . begin () ; i != characters . end () ; ++ i ) {
        if ( ! view -> print ( ofs, "\n" ) ) {
            view -> unableToSave();
            return;
        }
        if ( ! view -> print ( ofs, (*i) -> printStats () ) ) {
            view -> unableToSave();
            return;
        }
    }
    ofs . close();
}

/**
 * checks wheter the position is correct or not
 * @param x - represents parameter compared with width
 * @param y - represents parameter compared with height
 * @return
 */
bool CMap::correctPosition( size_t x, size_t y ) {
    if ( x >= height || y >= width )
        return false;
    return true;
}

/**
 * swaps player with another character ( usually nullpointer )
 * @param x - where to move horizontally
 * @param y - where to move vertically
 */
void CMap::move ( size_t x, size_t y ){
    pair <size_t, size_t> position = characters[0] -> getPosition();
    if ( ! correctPosition( position . first + x, position . second + y ) ) {
        view -> cannotMoveThere ();
        return;
    }
    CCharacter * player = characters[0];
    CCharacter * enemy = characters_map[position . first + x][position . second + y];
    if ( characters_map[position . first + x][position . second + y] != nullptr )
    {
        characters[0] -> interaction( enemy );
        if ( player -> stillAlive() == nullptr )
            player = nullptr;
        if ( enemy -> stillAlive() == nullptr ) {
            enemy = nullptr;
            for ( auto i = characters . begin () ; i != characters . end () ; ++ i )
                if ( *i == nullptr )
                    characters . erase ( i );
        }
        return;
    }
    characters_map[position . first + x][position . second + y] = characters[0];
    characters_map[position . first][position . second] = enemy;
    characters[0] -> setPosition( position . first + x, position . second + y );
    increasesMoves();
}

/**
 * prints the map into a string
 * @return
 */
string CMap::printMap () {
    stringstream strs;

    for ( size_t i = 0; i < width; i++ ) {
        for ( size_t j = 0; j < height; j++ ) {
            strs << terrain_map[i][j] -> print();
            if ( characters_map[i][j] == nullptr )
                strs << '_' ;
            else
                strs <<  characters_map[i][j] -> showChar();
            strs <<  " ";
        }
        strs << "\n";
    }
    return strs . str ();
}

void CMap::increasesMoves (){
    moves ++;
}
void CMap::decreaseMoves (){
    moves --;
}
/**
 * returns a string saying how many moves have been done
 * @return
 */
string CMap::showCounter() {
    string out = "moves: ";
    out . append ( to_string( moves ) ) . append ("\n");
    return out;
}
/**
 * cleans after itself - clears vectors
 */
void CMap::clean() {
    width = 0;
    height = 0;
    moves = 0;
    for ( auto i = terrain_map . begin () ; i != terrain_map . end () ; ++ i )
        for ( auto j = i -> begin () ; j != i -> end () ; ++ j )
            delete *j;
    for ( auto i = characters . begin () ; i != characters . end () ; ++i )
        delete *i;
    characters_map . clear ();
    terrain_map . clear ();
    characters . clear ();
}

CCharacter * CMap::getPlayer () const{
    return characters[0];
}

bool CMap::loseTheGame() {
    if ( characters[0] == nullptr )
        return true;
    return false;
}