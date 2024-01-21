#ifndef MEDICHERO_HPP_
#define MEDICHERO_HPP_
#include <iostream>
using namespace std;
#include "Hero.hpp"

class MedicHero : public Hero{
	private:
		int healAmount;
	public:
		MedicHero();
		MedicHero(int healAmount, Gun *gun, int hp, Point position);
		~MedicHero();
		int getHealAmount() const;
		void setHealAmount(int healAmount);
		void useSpecial();
};

#endif /* MEDICHERO_H_ */
