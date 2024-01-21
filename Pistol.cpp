#include "Pistol.hpp"
#include "Gun.hpp"
#include "Hero.hpp"
#include <iostream>
using namespace std;

Pistol::Pistol() : Gun("Pistol",16, 30, 2) {
	this->setType('L');
}

Pistol::~Pistol() {
}

void Pistol::useSpecial(Hero& h1, Object** map){
	// Fire in all 4 directions
	Point p = h1.getPosition();
	for (int i = p.x - 1; i <= p.x + 1; ++i) {
		for (int j = p.y - 1; j <= p.y + 1; ++j) {
			if (i >= 0 && i < 15 && j >= 0 && j < 15) {
				if (map[i][j].getType() == 'S') {
					h1.getGun()->setBullets(h1.getGun()->getBullets() - 1);
					map[i][j] = Object('O');
				}
			}
		}
	}
}
