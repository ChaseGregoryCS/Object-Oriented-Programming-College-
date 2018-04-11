#include "Player.h"
#include <typeinfo>

using namespace GameSpace;
using namespace std;

Player::Player(): p(NULL) {}

Player::Player(string name, Player::PlayerType type):p(NULL){
	switch (type){
		case WARRIOR:   p = new Warrior(name);
			        break;
		case HORNET:    p = new Hornet(name);
			        break;
		case KILLERANT: p = new KillerAnt(name);
			        break;
		case SPIDER:    p = new Spider(name);
			        break;
		default:        p = new Explorer(name);
					break;
	}
}

Player::Player(const Player& pl): p(NULL){
	CopyStuff(pl);
}

Player::Player(PlayerClass * ptr): p(ptr){
}

Player::~Player(){ delete p; p = NULL;}

void Player::CopyStuff(const Player& pl){
  	delete p;
	p = NULL;
	if(pl.p){
		p = pl.p->Clone();
	}
	return;
}

string Player::Name() const{
	if(p)
		return p->Name();
	return "";
}

char Player::DirChar() const{
	if(p)
		return p->DirChar();
	return ' ';
}

bool Player::IsAlive() const{
	if(p)
		return p->IsAlive();
	return false;
}

bool Player::IsDead() const{
	if(p)
		return p->IsDead();
	return false;
}

bool Player::IsActive() const{
	if(p)
		return p->IsActive();
	return false;
}

int Player::Row() const{
	if(p)
		return p->Row();
	return -1;
}

int Player::Column() const{
	if(p)
		return p->Column();
	return -1;
}

DirType Player::Direction() const{
	if(p)
		return p->Direction();
	return EAST;
  
}

int Player::Health() const{
	if(p)
		return p->Health();
	return 0;
}

int Player::WillPower() const{
      if(p)
		return p->WillPower();
      return 0;
}

int Player::MaxSpeed() const{
	if(p)
		return p->MaxSpeed();
	return 0;
}

int Player::CurrentSpeed() const{
	if(p)
		return p->CurrentSpeed();
	return 0;
}

int Player::Power() const{
	if(p)
		return p->Power();
	return 0;
}

int Player::Armor() const{
	if(p)
		return p->Armor();
	return 0;
}

int Player::Momentum() const{
	if(p)
		return p->Momentum();
	return 0;
}

bool Player::IsMyEnemy(const Player& pc) const{
	if(p)
		return p->IsMyEnemy(pc.p);
	return false;
}

bool Player::Active(){
	if(p)
		return p->Active();
	return false;
}

bool Player::InActive(){
	if(p)
		return p->InActive();
	return false;
}

bool Player::Heal(){
	if(p)
		return p->Heal();
	return false;
}

bool Player::Dead(){
	if(p)
		return p->Dead();
	return false;
}

int Player::ResetMomentum(){
	if(p)
		return p->ResetMomentum();
	return 0;
}

int Player::UseMomentum(int num){
  	if(p)
		return p->UseMomentum(num);
	return 0;
}

bool Player::SetCell(int newRow, int newCol){
    	if(p)
		return p->SetCell(newRow, newCol);
	return 0;
}

bool Player::SetDir(GameSpace::DirType dir){
	if(p)
		return p->SetDir(dir);
	return false;
}

int Player::SlowDown(int hazard){
	if(p)
		return p->SlowDown(hazard);
	return 0;
}

int Player::ResetCurrentSpeed(){
	if(p)
		return p->ResetCurrentSpeed();
	return 0;
}

int Player::Wounded(int damage){
	if(p)
		return p->Wounded(damage);
	return 0;
}

int Player::Damage() const{
	if(p)
		return p->Damage();
	return 0;
}

int Player::Impact() const{
	if(p)
		return p->Impact();
	return 0;
}

bool Player::CriticalWound(){
	if(p)
		return p->CriticalWound();
	return false;
}

bool Player::DropWeapon(){
	Human * h = dynamic_cast<Human *> (p);
	if(h)
	      return h->DropWeapon();
	return false;
}

bool Player::GrabWeapon(string weapon, int skill){
	Human * h = dynamic_cast<Human *> (p);
	if(h)
	      return h->GrabWeapon(weapon, skill);
	return false;
}

bool Player::HasWeapon() const{
	const Human * h = dynamic_cast<const Human *> (p);
	if(h)
	      return h->HasWeapon();
	return false;
}

int Player::WeaponSkill() const{
	const Human * h = dynamic_cast<const Human *> (p);
	if(h)
	      return h->WeaponSkill();
	return 0;
}

string Player::WeaponName() const{
	const Human * h = dynamic_cast<const Human *> (p);
	if(h)
	      return h->WeaponName();
	return "";
}
  
bool Player::Move(){
      if(p)
		return p->Move();
      return false;
}

bool Player::MoveUnits(int x){
	if(p)
		return p->MoveUnits(x);
	return false;
}

bool Player::CanRun() const{
	if(p)
		return p->CanRun();
	return false;
}

bool Player::Run(){
	if(p)
		return p->Run();
	return false;
}

void Player::Display(ostream& out) const{
	if(p)
		p->Display(out);
	return;
}

Player& Player::operator=(const Player& pl){
	if(this != &pl){
		CopyStuff(pl);
	}
	return *this;
}

bool Player::operator==(const Player& pc) const{
	if(p and pc.p)
		return *p == *pc.p;
	return false;
}

bool Player::operator!=(const Player& pc) const{
	if(p and pc.p)
		return *p != *pc.p;
	return false;
}

bool Player::operator>=(const Player& pc) const{
	if(p and pc.p)
		return *p >= *pc.p;
	return false;
}

bool Player::operator<=(const Player& pc) const{
	if(p and pc.p)
		return *p <= *pc.p;
	return false;
}

bool Player::operator>(const Player& pc) const{
	if(p and pc.p)
		return *p > *pc.p;
	return false;
}

bool Player::operator<(const Player& pc) const{
	if(p and pc.p)
		return *p < *pc.p;
	return false;
}

ostream& operator<<(ostream& out, const Player& pl){
	pl.Display(out);
	return out;
}
