#ifndef HERO_HPP_
#define HERO_HPP_
#include <iostream>
using namespace std;

#include "Character.hpp"
#include "Ammo.hpp"
#include "Potion.hpp"
#include "Monster.hpp"
class Gun;

class Hero : public Character{
public:
	Hero();
	Hero(Gun *gun, int hp, Point position);
	~Hero();
	Gun*& getGun();
	void setGun(Gun *&gun);
	friend ostream& operator<<(ostream& out, Hero& h);
	Hero operator + (Ammo a);
	Hero operator + (Potion p);
	Hero operator - (Monster m);
	virtual void useSpecial();
	bool isStandingInDiagonal() const;
	private:
		Gun *gun;
};

#endif /* HERO_H_ */
