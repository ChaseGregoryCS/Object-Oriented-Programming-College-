#include <iostream>
#include <string>

#include "player4.h"
#include "Human.h"
#include "Warrior.h"
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

const int Warrior::VAR_STATS[8] = {5, 81, 9, 9, 5, 0, -1, -1};
const int Warrior::CONST_STATS[5] = {5, 81, 8, 3, 6};
const string  Warrior::WPN_NAME = "RIFLE";
const int  Warrior::WPN_SKILL = 5;


/******CONSTRUCOTRS********/
Warrior::Warrior(): Human("DEFAULT", CONST_STATS, VAR_STATS, WPN_NAME, WPN_SKILL){}

Warrior::Warrior(string player_name): 
				Human(player_name, CONST_STATS, VAR_STATS, WPN_NAME, WPN_SKILL){}

				
/*********METHODS***********/


Warrior * Warrior::Clone() const{
	return new Warrior(*this);
}

void Warrior::Display(ostream& out) const{ 
	out << "W";
	Human::Display(out);
}