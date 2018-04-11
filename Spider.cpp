#include <iostream>
#include <string>

#include "player4.h"
#include "Bug.h"
#include "Spider.h"
#include "dice.h"
#include "board4.h"

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctype.h>
#include <typeinfo>
#include <typeinfo>

using namespace std;
using namespace GameSpace;
/***CONSTATNTS***/

const int Spider::VAR_STATS[8] = {15, 50, 8, 11, 15, 0, -1, -1};
const int Spider::CONST_STATS[5] = {15, 20, 7, 2, 6};


/******CONSTRUCOTRS********/
Spider::Spider(): Bug("DEFAULT", CONST_STATS, VAR_STATS){}

Spider::Spider(string player_name): 
				Bug(player_name, CONST_STATS, VAR_STATS){}

				
/*********METHODS***********/
bool Spider::Move(){ 
	bool rValue = false;
	int moves = 0;
	int count = 0;
	int turns = 0;
	bool goodDir = false;
	DirType dir = EAST;
	goodDir = SetDir(dir);
	if(IsActive()){
		while(turns < 4 and Momentum() > 0){
			if(!goodDir) SetDir(NORTH);
			if(moves < (1 + int(count/2)) and MoveUnits(1) and Momentum() > 0){
				moves++;
				rValue = true;
				turns = 0;
			}else{
				goodDir = SetDir(DirType(Direction() + 1));
				if(dir == Direction()) goodDir = SetDir(DirType(Direction() + 1));
			
				if(!(moves < ( 1 +count/2))){
					count ++;
					moves = 0;
					dir = Direction();
				}else turns++;
			}
		}
//	Display(cout);
	}	
	return rValue;
}


void Spider::Display(ostream& out) const{ 
	out << "S";
	Bug::Display(out);
}

bool Spider::IsMyEnemy(const PlayerClass * p) const{
	return (typeid(Spider) != typeid(*p));
      
}

Spider * Spider::Clone() const{
	return new Spider(*this);
}