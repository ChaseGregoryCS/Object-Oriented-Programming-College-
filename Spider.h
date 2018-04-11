/**
 * @author: Chase Gregory - applied
 * 330 OOP
 * Spider.h
**/

#ifndef SC_1
#define SC_1

#include <string>
#include <cstring>
#include "Bug.h"
#include "player4.h"


using namespace std;

class Spider: public Bug
{
	private:
		 /* 
		 Narrative: Default constructor for Human. Not necessarry, but I wantied it in my header for clarity
		 Pre-Conditions: Should never be called but constructs a default Human.
		 Post-Conditions: instantiated default Human.
		 */
		Spider();
	public:
	  
		/*
		Narrative: Used for Handle Class Construction
		Pre-Conditions: N/A
		Post-ConditionS: New player of itself returned
		 */
		virtual Spider * Clone() const;
	  
		/* 
		 Narrative: Parameterized constructor for Spider
		 Pre-Conditions: Client creates an Spider
		 Post-Conditions: Instantiated Spider with a player_name
		 */
		Spider(string player_name);
		
		/*
		Narrative: Moves the Spider initially EAST, if it cannot go in a direction it changes directions clockwise
			   moves in a square spiral. Stops when momentum is 0
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
	  

		/******CONSTANTS******/
		static const int VAR_STATS[8];
		static const int CONST_STATS[5];
};

#endif