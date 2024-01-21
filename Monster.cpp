#include "Monster.hpp"
using namespace std;
#include "Character.hpp"

Monster::Monster():Character(){
	name = "";
	this->setType('S');
}

Monster::Monster(string name, int hp, Point position):Character(hp, position){
	this->name = name;
	this->setType('S');
}

const string& Monster::getName() const {
	return name;
}

Monster::~Monster() {
}

void Monster::setName(const string &name) {
	this->name = name;
}
