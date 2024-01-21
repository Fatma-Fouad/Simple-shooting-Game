#include "Potion.hpp"
#include "Item.hpp"

Potion::Potion():Item(){
	healingAmount = 0;
	this->setType('N');
}

Potion::Potion(int healingAmount):Item(){
	this->healingAmount = healingAmount;
	this->setType('N');
}

int Potion::getHealingAmount() const {
	return healingAmount;
}

Potion::~Potion() {
}

void Potion::setHealingAmount(int healingAmount) {
	this->healingAmount = healingAmount;
}
