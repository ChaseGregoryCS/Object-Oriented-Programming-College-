#include <iostream>
#include <string>

#include "player4.h"
#include "Bug.h"
#include "KillerAnt.h"
#include "dice.h"

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctype.h>
#include <typeinfo>

using namespace std;

/***CONSTATNTS***/

const int KillerAnt::VAR_STATS[8] = {2, 20, 7, 5, 2, 0, -1, -1};
const int KillerAnt::CONST_STATS[5] = {2, 20, 10, 2, 6};


/******CONSTRUCOTRS********/
KillerAnt::KillerAnt(): Bug("DEFAULT", CONST_STATS, VAR_STATS){}

KillerAnt::KillerAnt(string player_name): 
				Bug(player_name, CONST_STATS, VAR_STATS){}

				
/*********METHODS***********/
bool KillerAnt::Move(){ 
	int rmom = Momentum();
	int i = 3;
	bool escFlag = true;
	SetDir(GameSpace::EAST);
	while ((Momentum() > 0) and escFlag){
		if(PlayerClass::MoveUnits(1)) i = 3;
		else if (!i) {
		  escFlag = false; 
		  SetDir(SwitchDir());
		}else{
			SetDir(SwitchDir());
			i--;
			
		}
// 		}else escFlag = false;
	}
	return rmom != Momentum();
}	



void KillerAnt::Display(ostream& out) const{ 
	out << "K";
	Bug::Display(out);
}

bool KillerAnt::IsMyEnemy(const PlayerClass * p) const{
	return (typeid(KillerAnt) != typeid(*p));
}

KillerAnt * KillerAnt::Clone() const{
	return new KillerAnt(*this);
}