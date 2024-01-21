#include "Ammo.hpp"
#include "Item.hpp"

Ammo::Ammo():Item(){
	bulletsCollected = 0;
	this->setType('A');
}

Ammo::Ammo(int bulletsCollected):Item(){
	this->bulletsCollected = bulletsCollected;
	this->setType('A');
}

Ammo::~Ammo(){

}

int Ammo::getBulletsCollected() const {
	return bulletsCollected;
}

void Ammo::setBulletsCollected(int bulletsCollected) {
	this->bulletsCollected = bulletsCollected;
}
