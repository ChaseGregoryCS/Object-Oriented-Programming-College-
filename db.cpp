#include "p4.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "db.h"
#include <algorithm>
#include <sstream>

using namespace std;

PlayerDB * PlayerDB::dBPointer = NULL;

PlayerDB::PlayerDB(){}

PlayerDB::PlayerDB(const PlayerDB&){}

PlayerDB::~PlayerDB(){}

PlayerDB * PlayerDB::GetDB(){
	if(!dBPointer)
		dBPointer = new PlayerDB();
	return dBPointer;
}

void PlayerDB::DeleteDB(){
	delete dBPointer;
	dBPointer = NULL;
}

bool PlayerDB::Load(istream& inStream){

	bool rValue = false;
	if(inStream.good()){
		
		string fields [2];
		int intFields [3];
//cout <<"InLoad"<<endl;
		while(GetInput(inStream, intFields, fields)){
//cout << "top of load loop\n";
			string type = fields[TYPE];
			Player p = Player(fields[NAME], CharToType(type[0]));
			p.Active();
			p.Wounded(p.Health() - intFields[HEALTH]);
			p.SlowDown(p.CurrentSpeed() - intFields[CURRSPD]);
			if(!intFields[ACTIVE])
				p.InActive();
			Add(p);
			if (!rValue){
				rValue = true;
			}
//	cout <<"add:"<<p.Name()<<endl;
		}
	}
	return rValue;
}

bool PlayerDB::GetInput(istream& inStream, int intFields[], string fields[]){

	int count = 0;
	bool stepAgain = true;
	char type;
	char temp;
	char stuff[255];
	if(inStream){
		inStream >> type >> temp >> intFields[ACTIVE] >> temp;
		getline(inStream, fields[NAME], '#');
		inStream >> intFields[HEALTH] >> temp >> intFields[CURRSPD];
	}
	if(inStream.fail())
	{
		stepAgain = false;
//	cout <<"fail"<<endl;
	}
	fields[TYPE] = type;
	inStream.ignore(256, '\n');
	return stepAgain;
}


Player::PlayerType PlayerDB::CharToType(char type){
	switch (type){
		case 'S': return Player::SPIDER;
		case 'H': return Player::HORNET;
		case 'K': return Player::KILLERANT;
		case 'W': return Player::WARRIOR;
		default: return Player::EXPLORER;
	}
}

bool PlayerDB::Dump(ostream& outStream){
	map<const string, Player>::iterator it;
	int i = 0;
	bool rValue = false;
	stringstream s;
	char type;
	for (it = DataMap.begin(); it != DataMap.end(); ++it){
		if(!rValue) rValue = true;
		i = 0;
		s << it->second;
		s >> type;
		s.ignore(256, '\n');
		outStream << type << "#" << it->second.IsActive() << "#"
		<< it->second.Name() << "#" << it->second.Health() << "#" << it->second.CurrentSpeed()
		<< "#" <<endl;
	}
	return rValue;
}


bool PlayerDB::Add(const Player& player){
	bool rValue = false;
	string upperName = GameSpace::Ucase(player.Name());
	if(!DataMap.count(upperName)){
		DataMap.insert(make_pair(upperName, player));
		rValue = true;
	}
	return rValue;
}

bool PlayerDB::Remove(const string& name){
	bool rValue = false;
	if(DataMap.count(GameSpace::Ucase(name))){
		rValue = true;
		DataMap.erase(GameSpace::Ucase(name));
	}
	return rValue;
}

bool PlayerDB::Retrieve(const string& name, /*who*/ Player& player){
	bool rValue = false;

	if(DataMap.count(GameSpace::Ucase(name))){
		rValue = true;
		map<const string, Player>::iterator it = DataMap.find(GameSpace::Ucase(name));
		player = it->second;
	}
	return rValue;
}


void PlayerDB::MakeEmpty(){
	DataMap.erase(DataMap.begin(), DataMap.end());
	return;
}

bool PlayerDB::IsEmpty(){
	return DataMap.empty();
}

int PlayerDB::NumberActive() const{
	int rValue = 0;
	bool active;
	if(DataMap.size()){
		map<const string, Player>::const_iterator it = DataMap.begin();
		while(it != DataMap.end()){
			if(it->second.IsActive())
				rValue++;
			it++;
		}
	      
	}
	return rValue;
}

int PlayerDB::NumberPlayers() const{
	return DataMap.size();
}

vector<string> PlayerDB::SortByName() const{
	vector<string> rVec;

	map<const string, Player>::const_iterator it = DataMap.begin();
	while (it != DataMap.end()){
		rVec.push_back(it->second.Name());
		it++;
	}
	sort(rVec.begin(), rVec.end());
	return rVec;
	
}

vector<string> PlayerDB::SortBySpeed() const{
	vector<Player> temp;
	vector<string> rVec;
	
	string holdMyName;
	
	map<const string, Player>::const_iterator it = DataMap.begin();
	while (it != DataMap.end()){
		temp.push_back(it->second);
		it++;
	}
	sort(temp.begin(), temp.end(), PlayerDB::SortSpeed);
	for (int i = 0; i < temp.size(); i++){
		holdMyName = temp[i].Name();
		rVec.push_back(holdMyName);
	}
	return rVec;
	
}

vector<string> PlayerDB::SortByHealth() const{
	vector<string> rVec;
	vector<Player> temp;
	string holdMyName;
	
	map<const string, Player>::const_iterator it = DataMap.begin();
	while (it != DataMap.end()){
		temp.push_back(it->second);
		it++;
	}
	sort(temp.begin(), temp.end(), PlayerDB::SortHealth);
	for (int i = 0; i < temp.size(); i++){
		holdMyName = temp[i].Name();
		rVec.push_back(holdMyName);
	}
	return rVec;
	
}

const pair<const string,Player>& PlayerDB::operator[](int index) const{
	int i = 0;
	
	if(index < 0)
		throw BELOW_VALID_INDEX;
	else if (index > DataMap.size() - 1)
		throw ABOVE_VALID_INDEX;

	map<const string, Player>::const_iterator it = DataMap.begin();
	while(i < index){
		i++;
		it++;
	}
	return *it;
}


bool PlayerDB::SortSpeed(const Player& p1, const Player& p2){
	return (p1.CurrentSpeed() < p2.CurrentSpeed());
}

bool PlayerDB::SortHealth(const Player& p1, const Player& p2){
	return (p1.Health() < p2.Health());
}

void PlayerDB::Display(ostream& out) const{
	map<const string, Player>::const_iterator it = DataMap.begin();
	while(it != DataMap.end()){
		out << it->second;
		it++;
	}
	return;
}

ostream& operator<<(ostream& out, const PlayerDB* db){
	if(db)
		db->Display(out);
	return out;
}