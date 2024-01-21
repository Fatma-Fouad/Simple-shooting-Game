#ifndef DEMOLITIONHERO_HPP_
#define DEMOLITIONHERO_HPP_
#include <iostream>
using namespace std;
#include "Hero.hpp"
#include "Gun.hpp"

class DemolitionHero : public Hero{
	public:
		DemolitionHero();
		DemolitionHero(Gun gun1, Gun *gun, int hp, Point position);
		~DemolitionHero();
		Gun& getGun1();
		void setGun1(Gun &gun1);
		void useSpecial();
	private:
		Gun gun1;
};

#endif /* DEMOLITIONHERO_H_ */
