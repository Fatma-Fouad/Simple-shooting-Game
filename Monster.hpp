#ifndef MONSTER_HPP_
#define MONSTER_HPP_
#include <iostream>
using namespace std;
#include "Character.hpp"

class Monster : public Character{
	private:
		string name;
	public:
		Monster();
		Monster(string name, int hp, Point position);
		~Monster();
		const string& getName() const;
		void setName(const string &name);
};

#endif /* MONSTER_H_ */
