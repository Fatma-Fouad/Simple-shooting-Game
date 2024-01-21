#include "Gun.hpp"
#include "Hero.hpp"
#include "Character.hpp"
#include "Object.hpp"
#include "MedicHero.hpp"
#include "DemolitionHero.hpp"
#include "Bazooka.hpp"
#include "Rifle.hpp"
#include "Pistol.hpp"
#include <cmath>

Hero::Hero():Character(){
	this->setType('H');
	this->setHp(100);
	Point p = {0,0};
	this->setPosition(p);
	gun = new Gun();
}

Hero::Hero(Gun *gun, int hp, Point position):Character(hp, position){
	this->setType('H');
	this->gun = gun;
}

Hero::~Hero() {
	delete gun;
}

Gun*& Hero::getGun() {
	return gun;
}

void Hero::setGun(Gun *&gun) {
	this->gun = gun;
}

ostream& operator<<(ostream& out, Hero& h){
	out << "Hero Info: HP=" << h.getHp() << " Position=(" << h.getPosition().x << ", " << h.getPosition().y << ")";
	    if (h.getType() == 'M') {
	        out << " Medic Hero HealAmount=" << static_cast<const MedicHero&>(h).getHealAmount();
	    } else if (h.getType() == 'D') {
	        out << " Demolition Hero Guns: " << *h.getGun() << " and " << static_cast<DemolitionHero&>(h).getGun1();
	    }
	    return out;
	return out;
}

Hero Hero :: operator + (Ammo a){
	this->gun->setBullets(this->gun->getBullets() + a.getBulletsCollected());
	return *this;
}

Hero Hero :: operator + (Potion p){
	this->setHp(this->getHp() + p.getHealingAmount());
	return *this;
}

Hero Hero :: operator - (Monster m){
	this->setHp(this->getHp() - 10);
	m.setHp(m.getHp() - 20);
	return *this;
}

void Hero::useSpecial(){
	if (this->getType() == 'M') {
		static_cast<MedicHero*>(this)->useSpecial();
	} else if (this->getType() == 'D') {
		static_cast<DemolitionHero*>(this)->useSpecial();
	}
}

bool Hero::isStandingInDiagonal() const {
	int dx = abs(getPosition().x - gun->getRange());
    int dy = abs(getPosition().y - gun->getRange());
    if(dx == dy){
        return true;
    }
    else
    	return false;

}
