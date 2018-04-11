/**
 * @author: Chase Gregory - applied
 * Program #1 header file
 * 330 OOP
 * Player1.h
**/

#ifndef P1_H
#define P1_H

#include <string>
#include <cstring>
#include "wpn.h"
#include "gamespace.h"


using namespace std;
using namespace GameSpace;

class PlayerClass{
	private:
		/*
		  Narrative: Default constructor for PlayerClass
		  Pre-Conditions: Instantiation of PlayerClass object if no parameters
		  Post-Conditions: Instantiated PlayerClass object 
		 */
		PlayerClass(); 
  
	protected:
		/*
		Narrative: Parameterized constructor #1 for PlayerClass
		Pre-Conditions: Instantiation of PlayerClass object if parameters
		Post-Conditions: Instantiated PlayerClass object
		 */
		PlayerClass(string NAME, const int CONST_STATS[], const int VAR_STATS[] );
	public:

		/*
		Narrative: Destructor for PlayerClass
		Pre-Conditions: termination of PlayerClass
		Post-Conditions: deleted pointers
		 */
		virtual ~PlayerClass(); 
		
		/*
		Narrative: Used for Handle Class Construction
		Pre-Conditions: N/A
		Post-ConditionS: New player of itself returned
		 */
		virtual PlayerClass * Clone() const = 0;
		
		/*
		Narrative: Observer for player_name
		Pre-Conditions: in-code call
		Post-Conditions: return name
		 */
		string Name() const; 
		
		/*
		Narrative: Second observer for direction returns a char for output
		Pre-Conditions: in-code call
		Post-Conditions: char returned to the corresponding first letter of DirType direction
		 */
		char DirChar() const; 
		
		/*
		Narrative: Observer for alive
		Pre-Conditions: in-code call
		Post-Conditions: return alive
		 */
		bool IsAlive() const; 
		
		/*
		Narrative: Observer for not alive
		Pre-Conditions: in-code call
		Post-Conditions: return not alive
		 */
		bool IsDead() const; 
		
		/*
		Narrative: checks to see if a player is active
		Pre-Conditions: in-code call
		Post-Conditions: return active
		 */
		bool IsActive() const;  
	
		/*
		Narrative: Observer for row
		Pre-Conditions: in-code call
		Post-Conditions: return row
		 */
		int Row() const; 
		
		/*
		Narrative: Observer for col
		Pre-Conditions: in-code call
		Post-Conditions: return col
		 */
		int Column() const; 
		
		/*
		Narrative: Observer for direction
		Pre-Conditions: In-code call
		Post-Conditions returns the DirType of direction
		 */
		DirType Direction() const; 
		
		/*
		Narrative: Observer for health
		Pre-Conditions: in-code call
		Post-Conditions: return health
		 */
		int Health() const; 
		
		/*
		Narrative: Observer for will_power
		Pre-Conditions: in-code call
		Post-Conditions: return will_power
		 */
		int WillPower() const; 
		
		/*
		Narrative: Observer for max_speed
		Pre-Conditions: in-code call
		Post-Conditions: return max_speed
		 */
		int MaxSpeed() const; 
		
		/*
		Narrative: Observer for curr_speed
		Pre-Conditions: in-code call
		Post-Conditions: return curr_speed
		 */
		int CurrentSpeed() const; 
		
		/*
		Narrative: Observer for power
		Pre-Conditions: in-code call
		Post-Conditions: return power
		 */
		int Power() const; 
		
		/*
		Narrative: Observer for armor
		Pre-Conditions: in-code call
		Post-Conditions: return armor
		 */
		int Armor() const; 
		
		/*
		Narrative: Observer for momentum
		Pre-Conditions: in-code call
		Post-Conditions: return momentum
		 */
		int Momentum() const; 
		
		/*
		Narrative: Gets dice roll
		Pre-Conditions: displaying Dice Roll
		Post-Conditions: returns corresponding dice roll num
		 */
		int DiceRoll() const; 
		
		/*
		Narrative: Gets dice face
		Pre-Conditions: displaying Dice face
		Post-Conditions: returns corresponding dice face num
		 */
		int DiceFace() const; 
		
		/*
		Narrative: Checks a player to determine if it is an enemy
		Pre-Conditions: Pure Virtual, if called uses the method relative to the PlayerClass types 
		Post-Conditions: return true if enemy false otherwise
		 */
		virtual bool IsMyEnemy(const PlayerClass *p) const =0; 
		
		/*
		Narrative: Transformer for active
		Pre-Conditions: in code call
		Post-Conditions: returns bool if successfully changed and active = true
		 */
		bool Active(); 
		
		/*
		Narrative: reverse logic Transformer for active
		Pre-Conditions: in code call
		Post-Conditions: returns bool if successfully changed and active = false
		 */
		bool InActive(); 
		
		/*
		Narrative: Transformer that sets values to a fully healed state
		Pre-Conditions: in code call
		Post-Conditions: returns true indicating success and healed
		 */
		bool Heal(); 
		
		/*
		Narrative: Transformer that sets values to a dead state
		Pre-Conditions: in code call
		Post-Conditions: returns true indicating success and dead
		 */
		bool Dead(); 
		
		/*
		Narrative: Transformer that resets momentum
		Pre-Conditions: in code call
		Post-Conditions: sets momentum to the current speed
		 */
		int ResetMomentum(); 
		
		/*
		Narrative: Method that allows a player to use its momentum
		Pre-Conditions: in code call
		Post-Conditions: returns momentum
		 */
		int UseMomentum(int num); 
		
		/*
		Narrative: transformer for row and column
		Pre-Conditions: in code call
		Post-Conditions: returns bool true successfully transformed, false otherwise
		 */
		bool SetCell(int newRow, int newCol); 
		
		/*
		Narrative: transformer for direction
		Pre-Conditions: in code call
		Post-Conditions: returns true if successfully transformed, false otherwise
		 */
		bool SetDir(GameSpace::DirType dir); 
		
		/*
		 Narrative: Updates and returns the player’s current speed
		 Pre-Conditions: in-code call
		 Post-Conditions: updated current speed
		 */
		int SlowDown(int hazard); 
		
		/*
		Narrative: Updates player’s current speed to default MaxSpeed
		Pre-Conditions: in-code call
		Post-Conditions: player’s current speed is reset to Max speed
		 */
		int ResetCurrentSpeed(); 
		
		/*
		Narrative: Updates player’s health No change if the player is dead
		Pre-Conditions: in-code call
		Post-Conditions: player’s health is updated to health - damage
		 */
		int Wounded(int damage); 
		
		/*
		Narrative: Gets the amount of damage the player can give
		Pre-Conditions: in-code call
		Post-Conditions: returns an int based on the roll and the weapon skill
		 */
		virtual int Damage() const; 
		
		/*
		Narrative: gets the impact of the critical wound.
		Pre-Condition: in-code call or CriticalWound( ) has been called
		Post-Conditions: returns an int based on the critcal wound table
		 */
		virtual int Impact() const; 
		
		/*
		Narrative: Updates the willpower of the player based on the critical wound
		Pre-Condition: in-code call
		Post-Condition: returns bool based on if the player is alive
		 */
		bool CriticalWound(); 
		
		/*
		Narrative: Display values in specified order
		Pre-condition: ‘<<’ operator called
		Post-Conditions: Nothing
		 */
		virtual void Display(ostream& out) const; 
		
		/*
		Narrative: Pure Virtual for Move
		Pre-Conditions: N/A
		Post-Conditions: true if successful move false otherwise
		 */
		virtual bool Move() = 0; 
		
		/*
		Narrative: Moves Player x many times in current direction
		Pre-Conditions: Any move called
		Post-Conditions: true if successful move false otherwise
		 */
		bool MoveUnits(int x); 
		
		/*
		Narrative: Checks to see if the player can move north
		Pre-Conditions: Run Called
		Post-Conditions: true if the player can run North
		 */
		bool CanRun() const; 
		
		/*
		Narrative: Moves the player once in the North direction
		Pre-Conditions: N/A
		Post-Conditions: True if successful move false otherwise
		 */
		bool Run(); 
		
		/*
		Narrative: Equivalent operator override
		Pre: in code call
		Post: bool returned if successful operation
		 */
		bool operator==(const PlayerClass& p); 
		
		/*
		Narrative: not equivalent operator override
		Pre: in code call
		Post: bool returned if successful operation
		 */
		bool operator!=(const PlayerClass& p); 
		
		/*
		Narrative: Less than operator override
		Pre: in code call
		Post: bool returned if successful operation
		 */
		bool operator<(const PlayerClass& p); 
		
		/*
		Narrative: greater than operator override
		Pre: in code call
		Post: bool returned if successful operation
		 */
		bool operator>(const PlayerClass& p); 
		
		/*
		Narrative: less than or equal to operator override
		Pre: in code call
		Post: bool returned if successful operation
		 */
		bool operator<=(const PlayerClass& p); 
		
		/*
		Narrative: greater than or equal to operator override
		Pre: in code call
		Post: bool returned if successful operation
		 */
		bool operator>=(const PlayerClass& p); 
		
		/*
		 Narrative: greater than or equal to operator override
		 Pre: in code call
		 Post: bool returned if successful operation
		 */
		PlayerClass& operator=(const PlayerClass& p); 
		
		/*************************STATIC METHODS*******************************/
		/*
		 * Used to display debuggin information
		 */
		static void DebugStuff(); 
		static void DoneDebugStuff(); 
		
	protected:
		
		/*
		 Narrative: Rolls and indexes the impact table
		 Pre-Condition: Impact was called
		 Post-Condition: Impact value from index returned
		 */
		int ImpactTable(int power) const;
		
		 /*
		 Narrative: Rolls and indexes the CriticalWound table
		 Pre-Condition: CriticalWound was called
		 Post-Condition: wound value from index returned
		 */
		int WoundTable(int willpower) const;		

		static const int DEF_VAR_STATS[8];
		static const int DEF_CONST_STATS[5];
	
	private:
		enum VarStats {SPEED, HEALTH, WILLPOWER, POWER, MOMENTUM, ACTIVE, COL, ROW};
		enum ConstStats {MAX_SPEED, MAX_HEALTH, DEF_ARM_VAL, NUMDIE, NUMFACES};
		
		/*
		Narrative: Copies a player p into this player
		Pre-Conditions: copy constructor or = operator called
		Post-Conditions:deep copied object
		 */
		virtual void CopyStuff(const PlayerClass& p); 
		
		/*
		Narritive: Sets stats from INIT_STATS to stats_init NOTE: Private
		Pre-Conditions: Used in constructors, can be used to change stats
		Post-Conditions: a non “empty” stats_int array
		 */
		void SetStats(const int VAR_STATS[]); 
		  
		/*
		Narrative: Checks to see if the player name is a valid name. Returns DEF_NAME if the name is invalid.
		Pre-Conditions: Used in the parameterized constructors
		Post-Conditions: returns the name if all elements are alpha chars & one white space. Returns the                      
			DEF_NAME if the entered name is invalid.
		 */
		string ValidName(string name); 
		
		/*
		Narrative: Case sensative Compare. converts everything to upper and compares int values
		Pre-Conditions: Any of the operaors were called except for assignment
		Post-Conditions: int value returned from Compare operation
		 */
		int CompareName(const PlayerClass& p); 
		
		/*
		Narrative: Validates the direction
		Pre-Conditions: SetDir has been called
		Post-Conditions: a bool has been returned if the dir entered is valid.
		 */
		bool ValidDir(DirType dir); 
		
		
		/*******************VARIABLES********************************/
		int stats[8];//SPEED, HEALTH, WILLPOWER, POWER, MOMENTM, ACTIVE, COL, ROW In that order

		DirType dir;
		const string NAME; 
		const int * const STATS;//MAX_SPEED, MAX_HEALTH, DEF_ARM_VAL, NUMDIE, NUMFACES in that order
		
		/****CONSTANTS****/
  		static const string DEF_NAME;	
		static const int DEAD;
		static const DirType DEF_DIR;
		static const int HEAL_VALUE;
		static const int NUM_CONST_STATS;
		static const int NUM_VAR_STATS;
		static const int IMPACT_TABLE[11][11];
		static const int CRITICAL_WOUND[11][11];
		static bool debugSegF;

};
		/*
		Narrative: ostream out operator override
		Pre: in code call
		Post: bool returned if successfull operation
		 */
		ostream& operator<<(ostream& out, const PlayerClass* p);
#endif