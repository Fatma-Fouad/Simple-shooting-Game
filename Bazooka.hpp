#ifndef BAZOOKA_HPP_
#define BAZOOKA_HPP_
#include "Gun.hpp"
#include <iostream>
using namespace std;

class Bazooka : public Gun{
	public:
		Bazooka();
		~Bazooka();
		void useSpecial(Hero& h1, Object** map);
};

#endif /* BAZOOKA_H_ */
