/**
 * @author: Chase Gregory - applied
 * 330 OOP
 * Bug.h
**/

#ifndef BC_1
#define BC_1

#include <string>
#include <cstring>
#include "gamespace.h"
#include "player4.h"


using namespace std;
using namespace GameSpace;

class Bug: public PlayerClass
{
 	private:
		/* 
		 Narrative: Default constructor for bug. Not necessarry, but I wantied it in my header for clarity
		 Pre-Conditions: Should never be called but constructs a default bug.
		 Post-Conditions: instantiated default bug.
		 */
		Bug();
	protected:
		/* 
		 Narrative: Parameterized constructor for bug.
		 Pre-Conditions: Parameterized constructor for any derived class called.
		 Post-Conditions: instantiated bug.
		 */
		Bug(string player_name, 
			   const int CONST_STATS[], 
			   const int VAR_STATS[]);
		
		/*
		Narrative: Switches direction clockwise 
		Pre-Conditions: N/A
		Post-Conditions: Direction + 1 returned
		 */
		DirType SwitchDir();
	public:	
	  
		/*
		Narrative: Used for Handle Class Construction
		Pre-Conditions: N/A
		Post-ConditionS: New player of itself returned
		 */
		virtual Bug * Clone() const = 0;
		
		/*
		Pure Virtual for move
		*/
		virtual bool Move() = 0;
	      
		/* 
		Narrative: Display values in specified order
		Pre-condition: ‘<<’ operator called
		Post-Conditions: Nothing
		 */
		virtual void Display(ostream& out) const;
};


#endif