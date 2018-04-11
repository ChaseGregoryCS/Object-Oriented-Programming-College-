/**
 * @author: Chase Gregory - applied
 * 330 OOP
 * KillerAnt.h
**/

#ifndef KC_1
#define KC_1

#include <string>
#include <cstring>
#include "Bug.h"
#include "player4.h"


using namespace std;

class KillerAnt: public Bug
{
	private:
	  	/* 
		 Narrative: Default constructor for Human. Not necessarry, but I wantied it in my header for clarity
		 Pre-Conditions: Should never be called but constructs a default Human.
		 Post-Conditions: instantiated default Human.
		 */
		KillerAnt();
	public:
	  
		/*
		Narrative: Used for Handle Class Construction
		Pre-Conditions: N/A
		Post-ConditionS: New player of itself returned
		 */
		virtual KillerAnt * Clone() const;
	  
		/* 
		 Narrative: Parameterized constructor for KillerAnt
		 Pre-Conditions: Client creates an KillerAnt
		 Post-Conditions: Instantiated KillerAnt with a player_name
		 */
		KillerAnt(string player_name);
		
		/*
		Narrative: Moves the KillerAnt 1 position initially EAST, if it cannot move 1 EAST it changes it's direction SOUTH
			   And so on. Stops when momentum is 0
		Pre-Conditions: N/A
		Post-Conditions: true if moved false otherwise
		 */
		virtual bool Move();

		/* 
		Narrative: Display values in specified order
		Pre-condition: ‘<<’ operator called
		Post-Conditions: Nothing
		 */
		void Display(ostream& out) const;
		
		/* 
		Narrative: Checks a player to determine if it is an enemy
		Pre-Conditions: if a player is nearby
		Post-Conditions: return true if enemy false otherwise
		 */
		bool IsMyEnemy(const PlayerClass * p) const;
	  
	private:

		/******CONSTANTS******/
		static const int VAR_STATS[8];
		static const int CONST_STATS[5];
};

#endif