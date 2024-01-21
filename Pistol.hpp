#ifndef PISTOL_HPP_
#define PISTOL_HPP_
#include <iostream>
using namespace std;

#include "Gun.hpp"

class Pistol : public Gun{
	public:
		Pistol();
		~Pistol();
		void useSpecial(Hero& h1, Object** map);
};

#endif /* PISTOL_H_ */
