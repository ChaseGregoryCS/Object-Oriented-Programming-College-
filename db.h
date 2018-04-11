#ifndef P1DB_
#define P1DB_


#include "p4.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class PlayerDB{
	public:
		//Enum that is the ExceptionType
		enum ExceptionType {BELOW_VALID_INDEX, ABOVE_VALID_INDEX};
		
		/*******************************METHODS****************************/
		//Destructor
		~PlayerDB();

		/**
		Narrative: Returns a pointer to the instance of PlayerDB
		Pre-Conditions: N/A
		Post-Conditions: Returns a pointer to the PlayerDB
		**/
		static PlayerDB * GetDB();

		/**
		Narrative: Deletes the instance of playerDB
		Pre-Conditions: GetDB() called and a pointer to the instance of PlayerDB created
		Post-Conditions: Deleted pointer
		**/
		static void DeleteDB();

		/**
		Narrative: Loads the data into the database from an inputstream inStream 
		Pre-Conditions: N/A
		Post-Conditions: true if successfull, false otherwise
		**/
		bool Load(istream& inStream);

		/**
		Narrative: dumps the data from the database into an outputstream outStream, in load format
		Pre-Conditions: N/A
		Post-Conditions: true if successfull, false otherwise
		**/
		bool Dump(ostream& outStream);

		/**
		Narrative: adds the player to the database
		Pre-Conditions: N/A
		Post-Conditions: true if successfull, false otherwise
		**/
		bool Add(const Player& player);

		/**
		Narrative: removes the player from the database
		Pre-Conditions: N/A
		Post-Conditions: true if successfull, false otherwise
		**/
		bool Remove(const string& name);

		/**
		Narrative: retrieves the player from the database
		Pre-Conditions: N/A
		Post-Conditions: true if successfull, false otherwise
		**/
		bool Retrieve(const string& name, /*who*/ Player& player);

		/**
		Narrative: makes the database empty
		Pre-Conditions: N/A
		Post-Conditions: The map is empty
		**/
		void MakeEmpty();
		
		/**
		Narrative: checks if the database is empty
		Pre-Conditions: N/A
		Post-Conditions: true if empty, false otherwise
		**/
		bool IsEmpty();
		
		/**
		Narrative: counts how many players are active
		Pre-Conditions: N/A
		Post-Conditions: returns the number of active players
		**/
		int NumberActive() const;
		
		/**
		Narrative: counts how many players in the database
		Pre-Conditions: N/A
		Post-Conditions: returns the number of players
		**/
		int NumberPlayers() const;
		
		/**
		Narrative: sorts the database into a vector by name
		Pre-Conditions: N/A
		Post-Conditions: returns a sorted vector of playerNames
		**/
		vector<string> SortByName() const;
		
		/**
		Narrative: sorts the database into a vector by name
		Pre-Conditions: N/A
		Post-Conditions: returns a sorted vector of playerSpeed
		**/
		vector<string> SortBySpeed() const;
		
		/**
		Narrative: sorts the database into a vector by Health
		Pre-Conditions: N/A
		Post-Conditions: returns a sorted vector of playerHealth
		**/
		vector<string> SortByHealth() const;
		
		/**
		Narrative: sorts the database into a vector by Health
		Pre-Conditions: N/A
		Post-Conditions: returns a sorted vector of playerHealth
		**/
		const pair<const string,Player> & operator[](int index) const;
		
		//Displays all of the players in standard format 
		void Display(ostream& out) const;
		
	private:
		enum SelectIndex {TYPE = 0, ACTIVE = 0, NAME = 1, HEALTH = 1, CURRSPD = 2}; 
	      
		
		/*******************************DATA MEMBERS****************************/
		//Instance of the database
		static PlayerDB * dBPointer;
		//The actual database
		map<const string, Player> DataMap;

		
		/*******************************METHODS****************************/
		//Constructor for the database Private because it's a singlton
		PlayerDB();

		
		//Copy Constructor
		PlayerDB(const PlayerDB&);
		
		/**
		Narrative: Takes a char and turns it into a PlayerType
		Pre-Conditions: Load method called
		Post-Conditions: a PlayerType corresponding to the char is returned
		**/
		Player::PlayerType CharToType(char type);
		
		/**
		Narrative: Gets the input from the stream and pushes the data into the arrays.
		Pre-Conditions: Load method called
		Post-Conditions: returns true if the load into the arrays were successfull, false otherwise
		**/
		bool GetInput(istream& inStream, int intFields[], string fields[]); 
		
		//Sort method overide, compares health of the two players
		static bool SortHealth(const Player& p1, const Player& p2);

		//Sort Method overide, compares speed of the two players
		static bool SortSpeed(const Player& p1, const Player& p2);

};	
	/**
	Narrative: displays all Players in the database
	Pre-Conditions: N/A
	Post-Conditions: returns the stream
	**/
	ostream& operator<<(ostream& out, const PlayerDB* db);

#endif