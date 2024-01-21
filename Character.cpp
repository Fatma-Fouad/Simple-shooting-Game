#include "Character.hpp"

Character::Character():Object('C'){
	hp = 0;
	position.x = 0;
	position.y = 0;
}

Character::Character(int hp, Point position):Object('C'){
	this->hp = hp;
	this->position = position;
}

int Character::getHp() const {
	return hp;
}

void Character::setHp(int hp) {
	this->hp = hp;
}

Point Character::getPosition() const {
	return position;
}

void Character::setPosition(Point position) {
	this->position = position;
}

Character::~Character(){

}
