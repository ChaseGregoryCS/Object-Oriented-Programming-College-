//Chase Gregory	- applied 				330 OOP 								PRG1CPP

#include <iostream>
#include <string>

#include "player4.h"
#include "wpn.h"
#include "dice.h"
#include "gamespace.h"
#include "board4.h"

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctype.h>



using namespace std;
using namespace GameSpace;

bool PlayerClass::debugSegF = false; //Used for pinpointing seg_faults in all Player functions:: true = show debug

/**************CONSTANTS********************/

const string PlayerClass::DEF_NAME = "DEFAULT";
const DirType PlayerClass::DEF_DIR = EAST;
const int PlayerClass::DEAD = 0;
const int PlayerClass::HEAL_VALUE = 10;
const int PlayerClass::NUM_CONST_STATS = 5;
const int PlayerClass::NUM_VAR_STATS = 8;

const int PlayerClass::DEF_CONST_STATS[5] = {0,0,0,0,0};
const int PlayerClass::DEF_VAR_STATS[8] = {0,0,0,0,0,0,0,0};
/******************CONST_TABLES*********************/
const int PlayerClass::IMPACT_TABLE[11][11] = { 
		  /*********************POWER RATIING**********/
/*DICE ROLL*/	  { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10}, //Okay, so I had a sitdown, and though to myself.
                  { 1,  2,  3,  4,  5,  6,  7,  8,  9, 10, -1}, //wouldnt it be more efficient to use -1 for the value of w
                  { 2,  3,  4,  5,  6,  7,  8,  9, 10, -1, -1}, //and use a integer table? Much, much more efficient.
                  { 3,  4,  5,  6,  7,  8,  9, 10, -1, -1, -1},
                  { 4,  5,  6,  7,  8,  9, 10, -1, -1, -1, -1},
                  { 5,  6,  7,  8,  9, 10, -1, -1, -1, -1, -1},
                  { 6,  7,  8,  9, 10, -1, -1, -1, -1, -1, -1},
                  { 7,  8,  9, 10, -1, -1, -1, -1, -1, -1, -1},
                  { 8,  9, 10, -1, -1, -1, -1, -1, -1, -1, -1},
                  { 9, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                  {10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};

const int PlayerClass::CRITICAL_WOUND[11][11] = { 
		  /********************WILLPOWER RATING********/
/*DICE ROLL*/	  {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1}, //Dido execpt ascii of k
		  {  0,  0,  0,  0,  0,  0,  0,  0,  0, -1, -1},
		  {  0,  0,  0,  0,  0,  0,  0,  0, -1, -1, -1},
		  {  0,  0,  0,  0,  0,  0,  0, -1, -1, -1, -1},
		  {  0,  0,  0,  0,  0,  0, -1, -1, -1, -1, -1},
		  {  0,  0,  0,  0,  0, -1, -1, -1, -1, -1, -1},
		  {  0,  0,  0,  0, -1, -1, -1, -1, -1, -1, -1},
		  {  0,  0,  0, -1, -1, -1, -1, -1, -1, -1, -1},
		  {  0,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		  {  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		  { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};

//ALSO: I refactored my code so that each method only has one return statement
//this kills a majority of the assembly jump statements making the methods more efficient

/********************CONSTRUCTORS******************/
PlayerClass::PlayerClass():NAME(DEF_NAME), STATS(DEF_CONST_STATS){ 
	SetStats(DEF_VAR_STATS);
}

PlayerClass::PlayerClass(string name, const int CONST_STATS[], const int VAR_STATS[]): NAME(ValidName(name)), STATS(CONST_STATS){ 
	SetStats(VAR_STATS);
}


void PlayerClass::SetStats(const int VAR_STATS[]){ 
	if(debugSegF)
		cout << "SetStats(): check" << endl;	

	dir = DEF_DIR;
	
	stats[NUM_VAR_STATS];
	int i;
	for (i = 0; i < NUM_VAR_STATS; i++){
		stats[i] = VAR_STATS[i];
	}
	
	if(debugSegF)
		cout << "SetStats(): success!" << endl;
	return;
}

/*********************DESTRUCTOR*****************/

PlayerClass::~PlayerClass(){}
/*******************OBSERVERS*********************/
string PlayerClass::Name() const{ 
	if(debugSegF){
		cout << "Name(): check" << endl;
	}
	return NAME;
}

char PlayerClass::DirChar() const{ 
	if(debugSegF)
		cout << "DirChar(): check" << endl;
	char direction;
	//switch on player type returns corresponding Char to the first letter of the PlayerClassType
	switch (dir){
	        case NORTH: direction = 'N';
				break;
	        case SOUTH: direction = 'S';
				break;
	        case EAST: direction = 'E';
				break;
	        case WEST: direction = 'W';
				break;
	}
	return direction;
}

bool PlayerClass::IsAlive() const{
	if(debugSegF)
		cout << "IsAlive(): check" << endl;
	return stats[HEALTH] > 0;
}

bool PlayerClass::IsDead() const{
  	if(debugSegF)
		cout << "IsDead(): check" << endl;
	return !stats[HEALTH] > 0;
}

bool PlayerClass::IsActive() const{
	if(debugSegF)
		cout << "IsActive(): check" << endl;
	return stats[ACTIVE];
}

int PlayerClass::Row() const{
  	if(debugSegF)
		cout << "Row(): check" << endl;
	return stats[ROW];
}

int PlayerClass::Column() const{
	if(debugSegF)
		cout << "Column(): check" << endl;
	return stats[COL];
}

DirType PlayerClass::Direction() const{
  	if(debugSegF)
		cout << "Direction(): check" << endl;
	return dir;
}

int PlayerClass::Health() const{
	if(debugSegF)
		cout << "Health(): check" << endl;
	return stats[HEALTH];
}

int PlayerClass::WillPower() const{
  	if(debugSegF)
		cout << "WillPower(): check" << endl;
	return stats[WILLPOWER];
}

int PlayerClass::MaxSpeed() const{
  	if(debugSegF)
		cout << "MaxSpeed(): check" << endl;
	return stats[MAX_SPEED];
}

int PlayerClass::CurrentSpeed() const{
  	if(debugSegF)
		cout << "CurrentSpeed(): check" << endl;
  	return stats[SPEED];
}

int PlayerClass::Power() const{
  	if(debugSegF)
		cout << "Power(): check" << endl;
  	return stats[POWER];
}

int PlayerClass::Armor() const{
  	if(debugSegF)
		cout << "Armor(): check" << endl;
	return STATS[DEF_ARM_VAL];
}

int PlayerClass::Momentum() const{
  	if(debugSegF)
		cout << "Momentum(): check" << endl;
  	return stats[MOMENTUM];
}

int PlayerClass::DiceRoll() const{
  	if(debugSegF)
		cout << "DiceRoll(): check" << endl;
	return STATS[NUMDIE];
}

int PlayerClass::DiceFace() const{
  	if(debugSegF)
		cout << "DiceFace(): check" << endl;
	return STATS[NUMFACES];
}

int PlayerClass::ImpactTable(int power) const{
	int rValue;
	int diceRoll = Dice::Roll(Name(), IMPACT, 2, 6);
	if (diceRoll < 2 or power < 2) rValue = 0;
	else rValue = IMPACT_TABLE[power - 2][diceRoll - 2];
	return rValue;
}

int PlayerClass::WoundTable(int willpower) const{
	int rValue;
	int roll = Dice::Roll(Name(), WOUND, 2, 6);
	if (roll < 2 and roll > 12) rValue = 1;
	else rValue = CRITICAL_WOUND[roll - 2][willpower]; 
	return rValue;
}

/******************TRANSFORMERS*******************/

bool PlayerClass::SetCell(int newRow, int newCol){
  	if(debugSegF)
		cout << "SetCell(): check" << endl;
	bool flag;
	if (newRow > -1 and newCol > -1){
		stats[ROW] = newRow;
		stats[COL] = newCol;
		flag = true;
	}else if(newRow == -1 and newCol ==-1){
		stats[ROW] = newRow;
		stats[COL] = newCol;
		flag = true;
	}else{ 
		flag = false;
	}
	return flag;
}

bool PlayerClass::SetDir(DirType direction){ 
  	if(debugSegF)
		cout << "SetDir(): check" << endl;
	bool flag = false;
	//Ensures that dir is an actual direction. Prevents future issues if dir is actually
	//in DirTypes scope.
	if (ValidDir(direction)){
		dir = direction;
		flag = true;
	}
	return flag;
}

int PlayerClass::SlowDown(int hazard){ 
	int currSpeed = CurrentSpeed();
	if (stats[ACTIVE]){
		if (hazard > 0){
			int speed = CurrentSpeed();
			speed = speed - hazard;
			if (speed <= 0){
				stats[MOMENTUM] = 0;
				currSpeed = 0;
			}else if(stats[MOMENTUM] > speed) { 
				stats[MOMENTUM] = speed;
				currSpeed = speed;
			}else currSpeed = speed;
		}
	} 
	stats[SPEED] = currSpeed;
	return currSpeed;
}

int PlayerClass::ResetCurrentSpeed(){ 
		return stats[SPEED] = STATS[MAX_SPEED];
}

int PlayerClass::Wounded(int damage){ 
	int thisHealth = Health();
	
	if (stats[ACTIVE] and (damage > 0)){
		int health = thisHealth;
		//subtract the damage from health check to see if the health <= 0
		health -= damage;
		if(health <= 0){
			//if health is <= 0 double tap them
			Dead();
			//double tapped. then set the return value to 0
			thisHealth = 0;
		}else
		//other wise just set the updated health to the return value
			thisHealth = health;
	}
	//modify stats[HEALTH] to the updated value
	stats[HEALTH] = thisHealth;
	return thisHealth; 
}

/*****************CLASS METHODS*************************/


bool PlayerClass::Active(){ 
  	if(debugSegF)
		cout << "Active(): check" << endl;
	bool flag;
	//checks to see if the player is IsAlive() if the player is set stats[ACTIVE] to 1
	if (IsDead())
		flag = false;
	else{
		stats[ACTIVE] = 1;
		flag = true;
	}
	return flag;
}

bool PlayerClass::InActive(){ 
  	if(debugSegF)
		cout << "InActive(): check" << endl;
	bool flag;
	if(IsAlive()){
	//checks to see if the player is stats[ACTIVE] if the player is set stats[ACTIVE] to 0
		if (stats[ACTIVE] == 0){
			flag = false;
		}else{
			stats[ACTIVE] = 0;
			flag = true;
		}
	}else{
		stats[ACTIVE] = 0;
		flag = true;
	}
	return flag;
}

bool PlayerClass::Heal(){ 
  	if(debugSegF)
		cout << "Heal(): check" << endl;
	bool flag = false;
	if (IsAlive()){
		//sets the value of heath back to the Default
		stats[HEALTH] += HEAL_VALUE;
			if (stats[HEALTH] > stats[MAX_HEALTH])
				stats[HEALTH] = stats[MAX_HEALTH];
		flag = true;
	}
	return flag;
}

bool PlayerClass::Dead(){
  	if(debugSegF)
		cout << "Dead(): check" << endl;
	stats[HEALTH] = 0;
	stats[WILLPOWER]= 0;
	stats[MOMENTUM] = 0;
// 		alive = false;
	InActive();
	return true;
}

int PlayerClass::ResetMomentum(){
  	if(debugSegF)
		cout << "ResetMomentum(): check" << endl;
	
	//sets stats[MOMENTUM] back to the player's current SPEED 
	int returnValue = 0;
	if (IsAlive()){
		stats[MOMENTUM] = stats[SPEED];
		returnValue = stats[MOMENTUM];
	}
	return returnValue;	 
}

int PlayerClass::UseMomentum(int num){ 
  	if(debugSegF)
		cout << "UseMomentum(): check" << endl;
	
	if ((num > 0) && IsActive()){
		//subtracts num from stats[MOMENTUM] and returns stats[MOMENTUM] after operation 0 if negative
			stats[MOMENTUM] -= num;
			if (stats[MOMENTUM] < 0) stats[MOMENTUM] = 0;
         }
   return stats[MOMENTUM];
}

int PlayerClass::Damage() const{ 
	int returnValue = 0;
	if (stats[ACTIVE]){
		int diceDam = Dice::Roll(Name(), DAMAGE, DiceRoll(), DiceFace());
		//if the dice was less than one we just want to hit them with the power of the player
		if (diceDam < 1) returnValue = Power();
		//otherwise combine the two
		else returnValue = diceDam + Power();
	}
	return returnValue;
}

int PlayerClass::Impact() const{ 
	int returnValue = 0;
	if (stats[ACTIVE]){
		int diceRoll, power;
		//makes the code easier to read
		power = Power();
		returnValue = ImpactTable(power);
	}
	return returnValue;
}

bool PlayerClass::CriticalWound(){ 
	bool flag = false;
	if (stats[ACTIVE]){
		int roll, wound;
		//Modify health and current speed
		stats[HEALTH] -= 10;
		stats[SPEED] /= 2;
		//double tap the player if the health is <= 0
		if (stats[HEALTH] <= 0) flag = !Dead();
		//otherwise set the stats[MOMENTUM] if it is > currSpeed
		else{
			if (stats[MOMENTUM] > stats[SPEED]) stats[MOMENTUM] = stats[SPEED];
			//rolll for wound
			roll = Dice::Roll(Name(), WOUND, 2, 6);
			//the player is still alive if the player's roll < 2 or > 12 then flag is true
			if (roll < 2 and roll > 12) flag = true;
			else{
				//otherwise index CRITICAL_WOUND
				wound = CRITICAL_WOUND[roll - 2][WillPower()]; 
				//if the wound is 0 then kill the player
				if (wound == 0) flag = !Dead();
				
				//otherwise decriment willPower by one and kill them if they have willpower <= 0 set flag appropriately
				else if (wound == -1){
					stats[WILLPOWER] -= 1;
					if (stats[WILLPOWER] <= 0) flag = !Dead();
					else flag = true;
				}
			}
		}
	}
	//return the flag
	return flag;
  
}

bool PlayerClass::MoveUnits(int x){
	Board * bd = Board::GetBd();
	int rmom = Momentum();
	if(IsActive()){
		bd->MoveForward(this, x);
	}
	//delete bd;
	bd = NULL;
	return rmom != Momentum();
}

bool PlayerClass::CanRun() const{
  	Board * bd = Board::GetBd();
	bool rValue = false;
	if (IsActive()){
		int runValue = bd->Board::RunCost(this);
		if( (Momentum() >= runValue)){
			rValue = true;
		}
	}
	bd = NULL;
	return rValue;
}

bool PlayerClass::Run(){
  	Board * bd = Board::GetBd();
	DirType temp = Direction();
	
	bool rValue = false;
	if (IsActive() and CanRun()){
		SetDir(NORTH);
		if(MoveUnits(1)){
			rValue = true;
		}
		if(!rValue) SetDir(temp);
	}
	bd = NULL;
// 	cout << "Run: " << rValue << endl;
	//delete bd;
	return rValue;
}

void PlayerClass::Display(ostream& out) const{ 
//if the referenced player's weapon name != the empty string do first output else weaponless output
	out << "#" << IsActive() << "#" << Name() << "#(" << Row() << "," 
	<< Column() << "," << DirChar() <<")#" << Health() << "#" << WillPower() << 
	"#" << CurrentSpeed() << "#" << Momentum()<< "#" << Power() << "#" <<  
	DiceRoll() << "D" << DiceFace() << "#" << Armor() << "#";

}

/*****************STATIC METHODS*******************/

void PlayerClass::DebugStuff(){ 
	debugSegF = true;
}

void PlayerClass::DoneDebugStuff(){ 
	debugSegF = false;
}

/******************VALIDATORS***********************/
string PlayerClass::ValidName(string name){ 
	//delete NAME;

	if(debugSegF){
		cout << "ValidName(): check" << endl;
	}

	//return DEF_NAME if name = ''
	if(name != ""){
		int i = 0;
		
		string reName = "";
		//take out tabs
		for(i = 0; i < name.length(); ++i){
			 if (name[i] == '\t')
				name[i] = ' ';
		}
		//take out double white spaces 
		for(i = 0; i < name.length(); ++i){
			if(!isspace(name[i]) || (reName.length() > 0 && reName[reName.length() -1] != ' ')){
			
			 //if the char at 'i' is a space, the length of reName is greater than 0
			 //and the char at reName 'i' - 1 is a space, push the char at
			 //'i' back on reName.
				reName += name[i];
			}
		}
		//take out the last char if it is a space
		if(reName[reName.length() -1] == ' ')
			reName = reName.substr(0,reName.length() -1);
		

		
		return reName;
	}
	
	return DEF_NAME;
}

bool PlayerClass::ValidDir(DirType dir){ 
	//swicth on dir return bool if it is a valid direction.
	bool flag = false;
	switch (dir){
		case NORTH: flag = true;
				break;
		case EAST: flag = true;
				break;
		case SOUTH: flag = true;
				break;
		case WEST: flag = true;
				break;
		default: flag = false;	
	}
	return flag;
}

/********************OVERRIDES***********************/
void PlayerClass::CopyStuff(const PlayerClass& p){

	*const_cast<int const **> (&STATS) = p.STATS;
	*const_cast<string*> (&NAME) = p.Name();
	dir = p.dir;
	for(int i = 0; i < NUM_VAR_STATS; ++i){
		stats[i] = p.stats[i];
	}

	return;
}

int PlayerClass::CompareName(const PlayerClass &p){ 

  	int i = 0;
	char t;
  
	//dynamic data initialize
	char * thisName = NULL;
	char * pName = NULL;
	
	thisName = new char[Name().length() + 1];
	pName = new char[p.Name().length() + 1];
	
	//copy names
	strcpy(thisName, Name().c_str());
	strcpy(pName, p.Name().c_str());
	
	//converts everything in thisName to upper for comparison
	i=0;
	while (thisName[i]){
		t = toupper(thisName[i]);
		thisName[i] = t;
		i++;
	}
	//converts everything in pName to upper for comparison
	i=0;
	while (pName[i]){
		t = toupper(pName[i]);
		pName[i] = t;
		i++;
	}

	//get comarison
	i = strcmp(thisName, pName);
	
	//GO AWAY POINTERS!!!!
  	delete[] pName;
  	delete[] thisName;
 	pName = NULL;
 	thisName = NULL;

	return i;
}

bool PlayerClass::operator==(const PlayerClass& p){ 
  	if(debugSegF)
		cout << "Operator==(): check" << endl;
	return (CompareName(p) == 0);
}

bool PlayerClass::operator!=(const PlayerClass& p){
    	if(debugSegF)
		cout << "Operator!=(): check" << endl;
	return (CompareName(p) != 0);
}

bool PlayerClass::operator<(const PlayerClass& p){ 
    	if(debugSegF)
		cout << "Operator<(): check" << endl;
	return (CompareName(p) < 0);
}

bool PlayerClass::operator>(const PlayerClass& p){ 
    	if(debugSegF)
		cout << "Operator>(): check" << endl;
	return (CompareName(p) > 0);
}

bool PlayerClass::operator<=(const PlayerClass& p){ 
    	if(debugSegF)
		cout << "Operator<=(): check" << endl;
	return (CompareName(p) <= 0);
}

bool PlayerClass::operator>=(const PlayerClass& p){ 
    	if(debugSegF) 
		cout << "Operator>=(): check" << endl;
	return (CompareName(p) >= 0 );
}

PlayerClass& PlayerClass::operator=(const PlayerClass& p){  
    	if(debugSegF)
		cout << "Operator=(): check" << endl;
	if (this != &p){
		CopyStuff(p);
	}
	return *this;
}

ostream& operator<<(ostream& out, const PlayerClass* p){ 
	p->Display(out);
	return out;
}



