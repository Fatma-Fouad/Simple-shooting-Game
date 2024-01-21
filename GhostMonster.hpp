#ifndef GHOSTMONSTER_HPP_
#define GHOSTMONSTER_HPP_
#include <iostream>
using namespace std;
#include "Monster.hpp"

class GhostMonster : public Monster{
	private:
		bool isVisble;
	public:
		GhostMonster();
		GhostMonster(string name, int hp, Point position);
		~GhostMonster();
		bool isIsVisble() const;
		void setIsVisble(bool isVisble);
};

#endif /* GHOSTMONSTER_H_ */
