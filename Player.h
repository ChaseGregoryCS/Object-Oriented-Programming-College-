 #ifndef _PL4Y3R_
#define _PL4Y3R_


#include "player4.h"
#include "Bug.h"
#include "Hornet.h"
#include "KillerAnt.h"
#include "Spider.h"
#include "Human.h"
#include "Warrior.h"
#include "Explorer.h"

using namespace std;
using namespace GameSpace;

class Player{
	public:
		enum PlayerType {EXPLORER, WARRIOR, HORNET, KILLERANT, SPIDER};
		
		//**********CONSTRUCTORS********************//
		Player();
		Player(string name, PlayerType type=EXPLORER);
		Player(const Player& p);
		Player(PlayerClass * ptr);
		~Player();


		//**********METHODS***********************//
		string Name() const;
		char DirChar() const;
		bool IsAlive() const;
		bool IsDead() const;
		bool IsActive() const;
		int Row() const; 
		int Column() const;
		DirType Direction() const;
		int Health() const; 
		int WillPower() const; 
		int MaxSpeed() const; 
		int CurrentSpeed() const; 
		int Power() const;
		int Armor() const; 
		int Momentum() const;
		bool IsMyEnemy(const Player& pc) const;
		bool Active(); 
		bool InActive(); 
		bool Heal();
		bool Dead();
		int ResetMomentum();
		int UseMomentum(int num);
		bool SetCell(int newRow, int newCol);
		bool SetDir(GameSpace::DirType dir);
		int SlowDown(int hazard);
		int ResetCurrentSpeed();
		int Wounded(int damage);
		int Damage() const;
		int Impact() const;
		bool CriticalWound();
		void Display(ostream& out) const;
		bool Move();
		bool MoveUnits(int x);
		bool CanRun() const; 
		bool Run(); 
		bool HasWeapon() const;
		int WeaponSkill() const;
		string WeaponName() const;
		bool DropWeapon(); 
		bool GrabWeapon(string weapon, int skill);
		/*****OBSERVERS******/
		Player& operator=(const Player& pl);
		bool operator==(const Player& pc) const;
		bool operator!=(const Player& pc) const;
		bool operator<=(const Player& pc) const;
		bool operator>=(const Player& pc) const;
		bool operator<(const Player& pc) const;
		bool operator>(const Player& pc) const;
		

	private:
		PlayerClass * p;

		void CopyStuff(const Player& p);
};
	ostream& operator<<(ostream& out, const Player& p);


#endif
