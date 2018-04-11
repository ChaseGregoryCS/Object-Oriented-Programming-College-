/**
 * @author: Chase Gregory - applied
 * 330 OOP
 * Hornet.h
**/

#ifndef HOC_1
#define HOC_1

#include <string>
#include <cstring>
#include "Bug.h"
#include "player4.h"


using namespace std;


class Hornet: public Bug
{
	private:
		/* 
		 Narrative: Default constructor for Explorer. Not necessarry, but I wantied it in my header for clarity
		 Pre-Conditions: Should never be called but constructs a default explorer.
		 Post-Conditions: instantiated default Explorer.
		 */
		Hornet();
	  
	public:
	  
		/*
		Narrative: Used for Handle Class Construction
		Pre-Conditions: N/A
		Post-Conditions: New player of itself returned
		 */
		virtual Hornet * Clone() const;
	  
		/* 
		 Narrative: Parameterized constructor for Hornet
		 Pre-Conditions: Client creates an Hornet
		 Post-Conditions: Instantiated Hornet with a player_name
		 */
		Hornet(string player_name);
		
		/*
		Narrative: Moves the Hornet 2 positions initially EAST, if it cannot move 2 EAST it changes it's direction SOUTH
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
		virtual bool IsMyEnemy(const PlayerClass * p) const;
	  
	private:

		/******CONSTANTS******/
		static const int VAR_STATS[8];
		static const int CONST_STATS[5];
};

#endif