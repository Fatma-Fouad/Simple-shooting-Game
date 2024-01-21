#include "GhostMonster.hpp"

GhostMonster::GhostMonster():Monster(){
	isVisble = true;
	this->setType('h');
}

GhostMonster::GhostMonster(string name, int hp, Point position):Monster(name, hp, position){
	this->setType('h');
	this->isVisble = true;
}

bool GhostMonster::isIsVisble() const {
	return isVisble;
}

GhostMonster::~GhostMonster() {
}

void GhostMonster::setIsVisble(bool isVisble) {
	this->isVisble = isVisble;
}

