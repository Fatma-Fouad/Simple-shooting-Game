#include "DemolitionHero.hpp"
#include "Gun.hpp"

DemolitionHero::DemolitionHero():Hero(){
	this->setType('D');
}

DemolitionHero::DemolitionHero(Gun gun1, Gun *gun, int hp, Point position):Hero(gun, hp, position){
	this->gun1 = gun1;
	this->setType('D');
}

Gun& DemolitionHero::getGun1(){
	return gun1;
}

DemolitionHero::~DemolitionHero() {

}

void DemolitionHero::setGun1(Gun &gun1) {
	this->gun1 = gun1;
}

void DemolitionHero::useSpecial(){
    Gun *temp = this->getGun();
    Gun* g = &gun1;
    this->setGun(g);
    gun1 = *temp;
}
