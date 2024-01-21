#ifndef TANKMONSTER_HPP_
#define TANKMONSTER_HPP_
#include <iostream>
using namespace std;
#include "Monster.hpp"

class TankMonster : public Monster {
	public:
		TankMonster();
		TankMonster(int shild, string name, int hp, Point position);
		~TankMonster();
		int getShild() const;
		void setShild(int shild);

	private:
		int shild;
};

#endif /* TANKMONSTER_H_ */
