#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <memory>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

/*
 * *************************************Character******************************************
 * */
class CCharacter {
protected:
    char name;
    pair <size_t, size_t> position;
    int max_health;
    int health;
    int attack;
public:
    CCharacter (){};
    char showChar () const { return name; }
    void setPosition ( size_t x, size_t y );
    pair <size_t, size_t> getPosition () const;
    bool correctPosition ( size_t x, size_t y) const;
    void recieveDmg ( int damage );
    void heal ( int health );
};
/*
 * *************************************PLayer - character******************************************
 * */
class CPlayer : public CCharacter {
protected:
public:
    CPlayer (){};
};
/*
 * *************************************NPC - character******************************************
 * */

class CNpc : public CCharacter {
protected:
public:
    CNpc (){};
    virtual void interact ();
};
/*
 * *************************************Monster - NPC - character******************************************
 * */
class CMonster : public CNpc {
protected:
public:
    CMonster (){};
};
/*
 * *************************************Wolf - monster - NPC - character******************************************
 * */
class CWolf : public CMonster {
protected:
public:
    CWolf (){};
};
/*
 * *************************************Bear - monster - NPC - character******************************************
 * */
class CBear : public CMonster {
protected:
public:
    CBear (){};
};
/*
 * *************************************Friend - NPC - character******************************************
 * */
class CFriend : public CNpc {
    protected:
public:
    CFriend (){};
};
/*
 * *************************************Terrain******************************************
 * */
class CTerrain {
protected:
    char name;
public:
    CTerrain (){};
};
/*
 * *************************************Road - terrain******************************************
 * */
class CRoad : public CTerrain {
protected:
public:
    CRoad (){};
};
/*
 * *************************************Woods - terrain******************************************
 * */
class CWoods : public CTerrain {
protected:
public:
    CWoods (){};
};
/*
 * *************************************Lava - terrain******************************************
 * */
class CLava : public CTerrain {
protected:
public:
    CLava (){};
};
/*
 * *************************************ControlPanel******************************************
 * */
class CControlPanel {
protected:
    size_t width;
    size_t height;
    int movesCounter;
    vector <vector<CTerrain*> > map;
    vector <CCharacter*> characters;
public:
    CControlPanel (){};
    bool loadMap ();
    void saveMap ();
    bool readChar ();
};

int main() {
    cout << "Hello, my Sandbox Game!" << endl;
    CControlPanel controler;
    //controler . loadMap ();
    return 0;
}