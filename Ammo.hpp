#ifndef AMMO_HPP_
#define AMMO_HPP_
#include "Item.hpp"

class Ammo : public Item{
	public:
		Ammo();
		Ammo(int bulletsCollected);
		~Ammo();
		int getBulletsCollected() const;
		void setBulletsCollected(int bulletsCollected);
	private:
		int bulletsCollected;
};

#endif /* AMMO_H_ */
