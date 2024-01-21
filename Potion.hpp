#ifndef POTION_HPP_
#define POTION_HPP_
#include "Item.hpp"

class Potion : public Item{
public:
	Potion();
	Potion(int healingAmount);
	~Potion();
	int getHealingAmount() const;
	void setHealingAmount(int healingAmount);

	private:
		int healingAmount;
};

#endif /* POTION_H_ */
