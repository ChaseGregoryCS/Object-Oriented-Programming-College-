#include <iostream>
#include <string>

#include "player4.h"
#include "Bug.h"
#include "wpn.h"
#include "dice.h"
#include "gamespace.h"

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctype.h>

using namespace std;
using namespace GameSpace;


/******CONSTRUCOTRS********/
Bug::Bug(): PlayerClass("DEFAULT", DEF_CONST_STATS, DEF_VAR_STATS){}

Bug::Bug(string player_name, const int CONST_STATS[], const int VAR_STATS[]): 
				PlayerClass(player_name, CONST_STATS, VAR_STATS){}

				
/*********METHODS***********/

void Bug::Display(ostream& out) const{ 
	PlayerClass::Display(out);
	out << endl;
}

DirType Bug::SwitchDir(){
	switch(PlayerClass::Direction()){
		case EAST: return SOUTH;
		case SOUTH: return WEST;
		case WEST: return NORTH;
		case NORTH: return EAST;
	}
}
