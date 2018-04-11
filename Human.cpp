#include <iostream>
#include <string>

#include "player4.h"
#include "Human.h"
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
Human::Human(): wpn(NULL), wpn_skill(0), PlayerClass("DEFAULT", DEF_CONST_STATS, DEF_VAR_STATS){}

Human::Human(string player_name, const int CONST_STATS[], 
		        const int VAR_STATS[], 
			const string WPN_NAME, 
		        const int WPN_SKILL): PlayerClass(player_name, CONST_STATS, VAR_STATS), 
					      wpn(NULL), wpn_skill(WPN_SKILL)
{ 
	wpn = new Weapon(WPN_NAME);
}

Human::Human(const Human& h): PlayerClass(h){ 
	wpn = NULL;
	CopyStuff(h);
}

Human::~Human()
{
	delete wpn;
	wpn = NULL;
}

/*********METHODS***********/
bool Human::Move(){ 
	return MoveUnits(1);
}

void Human::Display(ostream& out) const{ 
	PlayerClass::Display(out);
	if(HasWeapon())
	      out << WeaponName()<< "#" << WeaponSkill() << "#";
	out << endl;
}

bool Human::HasWeapon() const{ 
	bool rValue = false;
	if(wpn)
		rValue = true;
	return rValue;
}

string Human::WeaponName() const{ 
	string rValue = "";
	if(wpn)
		rValue = wpn->WeaponName();
	return rValue;
}

int Human::WeaponSkill() const{ 
	return wpn_skill;
}

bool Human::DropWeapon(){ 
	bool rValue = false;
	if (HasWeapon()){
		delete wpn;
		wpn = NULL;
		wpn_skill = 0;
		rValue = true;
	}
	return rValue;
}

bool Human::GrabWeapon(string weapon, int skill){ 
	bool rValue = false;
	if(skill > 0 and PlayerClass::IsActive()){
		if(Weapon::ValidWeapon(weapon)){
			DropWeapon();
			wpn = new Weapon(weapon);
			wpn_skill = skill;
			rValue = true;
		}
	}
	return rValue;

}

int Human::Damage() const{ 
	int returnValue = 0;
	if (PlayerClass::IsActive()){
		int diceDam;
		//if the player haas a weapon do the wepaon calculation to returnValue
		if (HasWeapon()){
			diceDam = wpn->WeaponDamage();
			if (diceDam < 1) returnValue = 0;
			else returnValue = diceDam + WeaponSkill();
		//otherwise we dont have the weapon so roll and set the value to returnValue
		}else{
			diceDam = Dice::Roll(Name(), DAMAGE, PlayerClass::DiceRoll(), PlayerClass::DiceFace());
			//if the dice was less than one we just want to hit them with the power of the player
			if (diceDam < 1) returnValue = PlayerClass::Power();
			//otherwise combine the two
			else returnValue = diceDam + PlayerClass::Power();
		}
	}
	return returnValue;
}

int Human::Impact() const{ 
	int rValue = 0;
	if (PlayerClass::IsActive()){
		int diceRoll, impact, power;
		//makes the code easier to read

		//if the player has a weapon then power is equal to the weapon's power
		if (HasWeapon())
			power = wpn->WeaponPower();
		//otherise just use the player's power
		else power = PlayerClass::Power();
		rValue = PlayerClass::ImpactTable(power);
	}
	return rValue;
}

Human& Human::operator=(const Human& h){ 
	if(this != &h){
		PlayerClass::operator=(h);
		CopyStuff(h);
	}
	return *this;
}

void Human::CopyStuff(const Human& h){ 
        delete wpn;
	wpn = NULL;
	wpn_skill = 0;
	
	int i;
	//why do exta work if we don't have to?
	if (h.wpn != NULL){
		wpn = new Weapon(h.wpn->Weapon::WeaponName());
		wpn_skill = h.wpn_skill;
	}

	//copy stats from p to this object
}


bool Human::IsMyEnemy(const PlayerClass * p) const{
	const Human * h = dynamic_cast<const Human *> (p);
	return !h;
}








