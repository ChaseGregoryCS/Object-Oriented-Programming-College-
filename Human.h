/**
 * @author: Chase Gregory - applied
 * 330 OOP
 * Human.h
**/

#ifndef HC_1
#define HC_1

#include <string>
#include <cstring>
#include "wpn.h"
#include "gamespace.h"
#include "player4.h"


using namespace std;
using namespace GameSpace;

class Human: public PlayerClass
{
	private:
		/* 
		 Narrative: Default constructor for Human. Not necessarry, but I wantied it in my header for clarity
		 Pre-Conditions: Should never be called but constructs a default Human.
		 Post-Conditions: instantiated default Human.
		 */
		Human();
	  
	protected:
		/*
		 Narrative: Parameterized Constructor for Human
		 Pre-Conditions: Derived class Parameterized Constructor called
		 Post-Conditions: Instantiated parameterized Human
		 */
		Human(string player_name, 
			   const int CONST_STATS[], 
			   const int VAR_STATS[], 
			   const string WPN_NAME, 
			   const int WPN_SKILL);
	public:
		/* 
		 Narrative: Copy Constructor for Humans, handles dynamic data for deep copy
		 Pre-Conditions: Copy constructor Called
		 Post-Conditions: Copy of 'h' put into this Human
		 */
		Human(const Human& h);
		
		/* 
		 Narrative:Destructor for Human
		 Pre-Conditions: Constructed Human or derived human
		 Post-Conditions: No dangeling pointers after destruction of Human
		 */
		virtual ~Human();
		
		/*
		Narrative: Used for Handle Class Construction
		Pre-Conditions: N/A
		Post-ConditionS: New player of itself returned
		 */
		virtual Human * Clone() const = 0;
		
		/* 
		Narrative: gets the impact of the critical wound.
		Pre-Condition: in-code call or CriticalWound( ) has been called
		Post-Conditions: returns an int based on the critcal wound table
		 */
		virtual int Impact() const;
		
		/* 
		Narrative: Gets the amount of damage the player can give
		Pre-Conditions: in-code call
		Post-Conditions: returns an int based on the roll and the weapon skill
		 */
		virtual int Damage() const;
		
		/* 
		Narrative: Checks a player to determine if it is an enemy
		Pre-Conditions: if a player is nearby
		Post-Conditions: return true if enemy false otherwise
		 */
		virtual bool IsMyEnemy(const PlayerClass * p) const;
		
		/*
		Narrative: Checks to see if player has a weapon
		Pre-Conditions: in-code call
		Post-Conditions: returns true if player has weapon false otherwise
		 */
		bool HasWeapon() const;
		
		/* 
		Narrative: drops the weapon being carried and grabs a new one
		Pre-Conditions: in-code call
		Post-Condtions: returns true if the player has the weapon, false otherwise
		 */
		bool GrabWeapon(string wpn, int skill);
		
		/* 
		Narrative: Observer for weapon_skill
		Pre-Conditions: in-code call
		Post-Conditions: return weapon_skill 0 if not available
		 */
		int WeaponSkill() const;
		
		/* 
		Narrative: Observer for player_wep
		Pre-Conditions: in-code call
		Post-Conditions: return player_wep, ‘null’ if not available
		 */
		string WeaponName() const;
		
		/* 
		Narrative: Drops the weapon leaving no weapon from the player
		Pre-Conditions: in-code call
		Post-Conditions: bool if human
		 */
		bool DropWeapon();
		
		/* 
		Narrative: Display values in specified order
		Pre-Conditions: ‘<<’ operator called
		Post-Conditions: Nothing
		 */
		virtual void Display(ostream& out) const;
		
		/*
		Narrative: Moves the Human player once in a direction.
		Pre-Conditions: N/A
		Post-Conditions: returned true if move successfull false otherwise
		 */
		virtual bool Move();
		
		/* 
		 Narrative: assignment operator override
		 Pre: in code call
		 Post: HUman& returned after deep copy
		 */
		Human& operator=(const Human& h);
		

	  
	private:
		
		/* 
		Narrative: Copies a Human h into this player
		Pre-Conditions: copy constructor or = operator called
		Post-Conditions: deep copied object
		 */
		virtual void CopyStuff(const Human& h);
		
		/******DATA FIELDS*******/
		
		Weapon * wpn;
		int wpn_skill;
};


#endif