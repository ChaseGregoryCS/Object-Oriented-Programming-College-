#include <iostream>
#include <string>

#include "board4.h"
#include "player4.h"
#include "Bug.h"
#include "Hornet.h"
#include "dice.h"

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctype.h>
#include <typeinfo>

using namespace std;

/***CONSTATNTS***/

const int Hornet::VAR_STATS[8] = {8, 60, 9, 10, 8, 0, -1, -1};
const int Hornet::CONST_STATS[5] = {8, 60, 8, 3, 6};


/******CONSTRUCOTRS********/
Hornet::Hornet(): Bug("DEFAULT", CONST_STATS, VAR_STATS){}

Hornet::Hornet(string player_name): 
				Bug(player_name, CONST_STATS, VAR_STATS){}

				
/*********METHODS***********/
bool Hornet::Move(){ 
	int rmom = Momentum();
	int i = 0;

	bool endFlag = true;
	
	SetDir(GameSpace::EAST);
	while((Momentum() > 0) and endFlag){
		if (MoveUnits(2))
			i = 0;

		else{
			i++;
			if (i == 4) endFlag = false;
			SetDir(SwitchDir());
		}
	}
	return rmom != Momentum();
}

void Hornet::Display(ostream& out) const{ 
	out << "H";
	Bug::Display(out);
}

bool Hornet::IsMyEnemy(const PlayerClass * p) const{
	return (typeid(Hornet) != typeid(*p));
}

Hornet * Hornet::Clone() const{
	return new Hornet(*this);
}