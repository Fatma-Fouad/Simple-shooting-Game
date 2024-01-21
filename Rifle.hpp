#ifndef RIFLE_HPP_
#define RIFLE_HPP_
#include "Gun.hpp"
#include <iostream>
using namespace std;

class Rifle : public Gun{
	public:
		Rifle();
		~Rifle();
		void useSpecial(Hero& h1, Object** map);
};

#endif /* RIFLE_H_ */
