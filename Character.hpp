#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_
#include <iostream>
using namespace std;

#include "Object.hpp"

struct Point{
	int x;
	int y;
};

class Character : public Object{
	public:
		Character();
		Character(int hp, Point position);
		~Character();
		int getHp() const;
		void setHp(int hp);
		Point getPosition() const;
		void setPosition(Point position);
	private:
		int hp;
		Point position;
};

#endif /* CHARACTER_H_ */
