//
// Created by student on 11.5.18.
//

#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

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
#include "treasure.h"
#include "stone.h"


CMap::CMap ( CView & myview )
        :   width ( 0 ),
            height ( 0 ),
            moves ( 0 ),
            max_moves ( 1000000 ),
            view ( &myview )
{
}

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
 * @return - true if correctly loaded
 */
bool CMap::load (){
    string srcFile;
    clean ();
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
        view -> print ( "Unable to read content\n" );
        return false;
    }
    if ( ! readCharacterInfo( ifs ) ){
        view -> print ( "Unable to read character info\n" );
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
        case LAVA_SYMBOL : tmp = new CLava ();
            break;
        case ROAD_SYMBOL : tmp = new CRoad ();
            break;
        case WOODS_SYMBOL : tmp = new CWoods ();
            break;
        case TREASURE_SYMBOL : tmp = new CTreasure ();
            break;
        case STONE_SYMBOL : tmp = new CStone ();
            break;
        default  :
            return false;
    }
    terrain_map[ lineNumber ] . push_back( tmp );
    return true;
}

/**
 * parses specific characters and creates objects if possible ( player is put on the beginning of the character vector )
 * @param character - character representing a specific type of character
 * @param lineNumber - what line is the program supposed to modify
 * @return
 */
bool CMap::addCharacter ( const char & character, size_t lineNumber ) {
    CCharacter * tmp;
    bool playerFlag = false;
    pair<size_t, size_t> pos = make_pair( lineNumber, characters_map[lineNumber] . size() );
    switch ( character ){
        case PLAYER_SYMBOL : tmp = new CPlayer ( pos, 100, 5 );
                   playerFlag = true;
                   if ( ! characters . empty () )
                       if ( characters[0] -> getSymbol() == PLAYER_SYMBOL )
                           return false;
            break;
        case FRIEND_SYMBOL : tmp = new CFriend ( pos );
            break;
        case BEAR_SYMBOL : tmp = new CBear ( pos );
            break;
        case WOLF_SYMBOL : tmp = new CWolf ( pos );
            break;
        case '_' : tmp = nullptr;
            break;
        default  :
            return false;
    }
    /* makes sure Player  */
    if ( playerFlag )
        characters . insert( characters . begin () , tmp );
    else if ( tmp != nullptr )
        characters . push_back( tmp );

    characters_map[ lineNumber ] . push_back( tmp );
    return true;
}

/**
 * reads header of the file
 * @param ifs - ifstream - certain load file
 * @return - false if not in the correct format
 */
bool CMap::readHeader ( ifstream & ifs ){
    string readStr;
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
    if ( ( ! readLine ( ifs, readStr, max_moves ) ) || readStr != "mxmvs:" )
        return false;
    return true;
}

/**
 * reads the contents of the map
 * @param ifs - ifstream - certain load file
 * @return - false if not in the correct format
 */
bool CMap::readContent ( ifstream & ifs ){
    string line;
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
            if ( ! addTerrain ( line[ j ], i  ) ){
                view -> print ( "Wrong terrain index\n" );
                return false;
            }
            if ( ! addCharacter ( line [ j + 1 ], i ) ){
                view -> print ( "Wrong character index\n" );
                return false;
            }
        }
    }
    return true;
}

/**
 * reads special character info such as health, attack, etc. ( used while loading a saved game )
 * @param ifs - ifstream - certain load file
 * @return - false if not in the correct format
 */
bool CMap::readCharacterInfo ( ifstream & ifs ) {
    string line;
    size_t value;
    size_t coordX;
    size_t coordY;
    while ( getline ( ifs, line ) . good () ){
        if ( ifs . eof () )
            break;
        if  ( line != "" )
            return false;
        if ( ( ! readLine ( ifs, line, coordX ) ) || line != "posiX:" )
            return false;
        if ( ( ! readLine ( ifs, line, coordY ) ) || line != "posiY:" )
            return false;
        if ( characters_map[ coordX ][ coordY ] == nullptr || ! correctPosition( coordX, coordY ) )
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
 * @param ifs - ifstream - certain load file
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
string CMap::printHeader () const {
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
    out . append ( "mxmvs:" );
    out . append ( to_string( max_moves ) );
    out . append ( "\n" );
    return out;
}

/**
 * saves the game into the relevant file
 * also checks wheter the mofification of the output file went well
 * @param ofs - file where the game will be saved
 */
void CMap::save () const {
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
bool CMap::correctPosition( size_t x, size_t y ) const {
    return ! ( x >= height || y >= width );
}

/**
 * swaps player with another character ( usually nullpointer )
 * @param x - where to move horizontally
 * @param y - where to move vertically
 */
void CMap::move ( int x, int y ){
    pair <size_t, size_t> position = getPlayer() -> getPosition();
    if ( ! correctPosition( position . first + x, position . second + y ) ) {
        view -> cannotMoveThere ();
        return;
    }
    increasesMoves();

    terrainEvent();
    CCharacter * enemy = characters_map[position . first + x][position . second + y];
    if ( characters_map[position . first + x][position . second + y] != nullptr )
    {
        getPlayer() -> interaction( enemy );
        if ( ! enemy -> stillAlive() ) {
            for ( auto i = characters . begin () ; i != characters . end () ; ++ i )
                if ( *i == enemy ) {
                    characters . erase( i );
                    delete enemy;
                    characters_map[position . first + x][position . second + y] = nullptr;
                    terrainInteraction ();
                    return;
                }
        }
        terrainInteraction ();
        /* when player interacts with another character, he stays in the same position */
        return;
    }
    characters_map[position . first + x][position . second + y] = getPlayer();
    characters_map[position . first][position . second] = enemy;
    getPlayer() -> setPosition( position . first + x, position . second + y );
    terrainInteraction ();
}

/**
 * prints the map into a string
 * @return - returns string representing the map
 */
string CMap::printMap () const {
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
/**
 * increases number of moves
 */
void CMap::increasesMoves (){
    moves ++;
}

/**
 * returns a string saying how many moves have been done
 * @return - returns string representing counter
 */
string CMap::showCounter() const {
    string out = "Moves: ";
    out . append ( to_string( moves ) ) . append ( " / " ) . append ( to_string( max_moves ) ) . append ("\n");
    return out;
}

/**
 * cleans after itself - clears vectors
 * used so a different game was able to be loaded
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

/**
 * @return - returns pointer to player
 */
CCharacter * CMap::getPlayer () const{
    return characters[0];
}

/**
 * circumstances under which the game is lost
 * @return - true if lost
 */
bool CMap::loseTheGame() const {
    if ( ! characters[0] -> stillAlive() || moves >= max_moves )
        return true;
    return false;
}

/**
 * circumstances under which the game is won
 * @return - true if won
 */
bool CMap::winTheGame() const {
    pair <size_t, size_t> positon = characters[0] -> getPosition();
    if ( terrain_map[positon . first][positon . second] -> print() == TREASURE_SYMBOL )
        return true;
    return false;
}

/**
 * makes every character interact with terrain which they stand on
 */
void CMap::terrainInteraction () const {
    pair <size_t, size_t> positon = getPlayer() -> getPosition();
    view -> print( terrain_map[positon . first][positon . second] -> interact( getPlayer() ) );
}

/**
 * does every terrain event, that is specified
 */
void CMap::terrainEvent() {
    lavaSpreading();
    terrainChange();
}

/**
 * check wheter there is lava in adjacent positions
 * @param x - horizontal position
 * @param y - vertical position
 * @return  - true if adjacent position is lava
 */
bool CMap::isAdjacentLava ( size_t x, size_t y ) const {
    if ( correctPosition( x - 1 , y ) )
        if ( terrain_map[x - 1][y] -> print() == LAVA_SYMBOL )
            return true;
    if ( correctPosition( x + 1 , y ) )
        if ( terrain_map[x + 1][y] -> print() == LAVA_SYMBOL )
            return true;
    if ( correctPosition( x , y - 1 ) )
        if ( terrain_map[x][y - 1] -> print() == LAVA_SYMBOL )
            return true;
    if ( correctPosition( x, y + 1 ) )
        if ( terrain_map[x][y + 1] -> print() == LAVA_SYMBOL )
            return true;
    return false;
}

/**
 * lava has 20% chance to spread to adjacent positions
 */
void CMap::lavaSpreading (){
    for ( size_t i = 0 ; i < terrain_map . size () ; i ++ ){
        for ( size_t j = 0 ; j < terrain_map[i] . size () ; j++ ){
            if ( isAdjacentLava ( i, j ) && rand() % 10 < 2 && terrain_map[i][j] -> print() != TREASURE_SYMBOL ){
                CLava * tmp = new CLava ();
                delete terrain_map[i][j];
                terrain_map[i][j] = tmp;
            }
        }
    }
}

/**
 * if the action in terrain (children) is defined it changes under defined circumstaces
 */
void CMap::terrainChange (){
    for ( size_t i = 0 ; i < terrain_map . size () ; i ++ ){
        for ( size_t j = 0 ; j < terrain_map[i] . size () ; j++ ){
            CTerrain * tmp = terrain_map[i][j] -> action();
            if ( tmp != nullptr ){
                delete terrain_map[i][j];
                terrain_map[i][j] = tmp;
            }
        }
    }
}
