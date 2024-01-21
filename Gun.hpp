#ifndef GUN_HPP_
#define GUN_HPP_

#include "Object.hpp"
#include <iostream>
using namespace std;
class Hero;

class Gun : public Object{
	private:
		string name;
		int bullets;
		int dmgamount;
		int range;
	public:
		Gun();
		Gun(string name, int bullets, int dmgamount, int range);
		~Gun();
		int getBullets() const;
		void setBullets(int bullets);
		int getDmgamount() const;
		void setDmgamount(int dmgamount);
		const string& getName() const;
		void setName(const string &name);
		int getRange() const;
		void setRange(int range);
		friend ostream& operator<<(ostream& out, Gun& g);
		virtual void useSpecial(Hero& h1, Object** map);
};

#endif /* GUN_HPP_ */
