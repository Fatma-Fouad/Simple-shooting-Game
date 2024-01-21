#include "Gun.hpp"
#include <iostream>
using namespace std;
#include "Object.hpp"

Gun :: Gun() :Object('g'){
	bullets = 0;
	dmgamount = 0;
	range = 0;
}

Gun :: Gun(string name, int bullets, int dmgamount, int range):Object('g'){
	this->name = name;
	this->bullets = bullets;
	this->dmgamount = dmgamount;
	this->range = range;
}

int Gun::getBullets() const {
	return bullets;
}

void Gun::setBullets(int bullets) {
	this->bullets = bullets;
}

int Gun::getDmgamount() const {
	return dmgamount;
}

void Gun::setDmgamount(int dmgamount) {
	this->dmgamount = dmgamount;
}

const string& Gun::getName() const {
	return name;
}

void Gun::setName(const string &name) {
	this->name = name;
}

int Gun::getRange() const {
	return range;
}

void Gun::setRange(int range) {
	this->range = range;
}

Gun::~Gun() {
}

ostream& operator<<(ostream& out, Gun& g){
    out << "Gun Info: Name = " << g.getName() << " Bullets = " << g.getBullets() << " DmgAmount = " << g.getDmgamount() << " Range = " << g.getRange();
	return out;
}


void Gun::useSpecial(Hero& h1, Object** map) {
}

