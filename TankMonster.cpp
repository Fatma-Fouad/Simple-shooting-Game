#include "TankMonster.hpp"

TankMonster::TankMonster():Monster(){
	shild = 0;
	this->setType('T');
}
TankMonster::TankMonster(int shild, string name, int hp, Point position):Monster(name, hp, position){
	this->shild = shild;
	this->setType('T');
}

int TankMonster::getShild() const {
	return shild;
}

TankMonster::~TankMonster() {
}

void TankMonster::setShild(int shild) {
	this->shild = shild;
}
