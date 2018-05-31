#include "character.h"
#include "player.h"
#include "friend.h"
#include "monster.h"
#include "bear.h"
#include "wolf.h"
#include "terrain.h"
#include "road.h"
#include "lava.h"
#include "woods.h"
#include "view.h"
#include "map.h"
#include "controlPanel.h"

using namespace std;

int main() {
    CView view ( cout );
    CControlPanel controler ( &view );
    controler . initialize ();
    return 0;
}