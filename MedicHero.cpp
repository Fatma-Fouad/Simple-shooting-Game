#include "MedicHero.hpp"
#include "Hero.hpp"

MedicHero::MedicHero():Hero(){
	this->setType('M');
	healAmount = 0;
}

MedicHero::MedicHero(int healAmount, Gun *gun, int hp, Point position):Hero(gun, hp, position){
	this->setType('M');
	this->healAmount = healAmount;
}

int MedicHero::getHealAmount() const {
	return healAmount;
}

MedicHero::~MedicHero() {
}

void MedicHero::setHealAmount(int healAmount) {
	this->healAmount = healAmount;
}

void MedicHero::useSpecial(){
	this->setHp(this->getHp()+this->getHealAmount());
	this->setHealAmount(0);
}
