#include <iostream>
#include <string>

#include "player4.h"
#include "Human.h"
#include "Explorer.h"
#include "wpn.h"
#include "dice.h"
#include "gamespace.h"

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctype.h>

using namespace std;
using namespace GameSpace;

/***CONSTATNTS***/

const int Explorer::VAR_STATS[8] = {8, 42, 7, 6, 8, 0, -1, -1};
const int Explorer::CONST_STATS[5] = {8, 42, 0, 1, 6};
const string Explorer::WPN_NAME = "PISTOL";
const int Explorer::WPN_SKILL = 10;


/******CONSTRUCOTRS********/
Explorer::Explorer(): Human("DEFAULT",CONST_STATS, VAR_STATS, WPN_NAME, WPN_SKILL){}

Explorer::Explorer(string player_name): 
				Human(player_name, CONST_STATS, VAR_STATS, WPN_NAME, WPN_SKILL){}

				
/*********METHODS***********/

void Explorer::Display(ostream& out) const{ 
	out << "E";
	Human::Display(out);
}

Explorer * Explorer::Clone() const{
	return new Explorer(*this);
}