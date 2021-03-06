/**
 * @author: Chase Gregory - applied
 * 330 OOP
 * Warrior.h
**/

#ifndef WC_1
#define WC_1

#include <string>
#include <cstring>
#include "wpn.h"
#include "gamespace.h"
#include "Human.h"
#include "player4.h"


using namespace std;
using namespace GameSpace;

class Warrior: public Human
{
	private:
		/* 
		 Narrative: Default constructor for Warrior. Not necessarry, but I wantied it in my header for clarity
		 Pre-Conditions: Should never be called but constructs a default Warrior.
		 Post-Conditions: instantiated default Warrior.
		 */
		Warrior();
	public:
	  
		/*
		Narrative: Used for Handle Class Construction
		Pre-Conditions: N/A
		Post-ConditionS: New player of itself returned
		 */
		virtual Warrior * Clone() const;
	  
		/* 
		 Narrative: Parameterized constructor for Warrior
		 Pre-Conditions: Client creates an Warrior or default PlayerClass
		 Post-Conditions: Instantiated Warrior with a player_name
		 */
		Warrior(string player_name);

		/* 
		Narrative: Display values in specified order
		Pre-condition: ‘<<’ operator called
		Post-Conditions: Nothing
		 */
		void Display(ostream& out) const;
		
	private:
	  
		/******CONSTANTS******/
		static const string WPN_NAME;
		static const int WPN_SKILL;
		static const int VAR_STATS[8];
		static const int CONST_STATS[5];
};


#endif
