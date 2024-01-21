#include "Rifle.hpp"
#include "Gun.hpp"
#include "Hero.hpp"
#include <iostream>
using namespace std;

Rifle::Rifle() : Gun("Rifle",30, 20, 4){
	this->setType('R');
}

Rifle::~Rifle() {
}

void Rifle::useSpecial(Hero& h1, Object** map){
	// Fire 3 rounds (left, right, and up)
	int range = 4;
	Point p = h1.getPosition();
	for (int i = p.y - 1; i >= p.y - range; --i) {
		if (i >= 0 && i < 15) {
			if (map[p.x][i].getType() == 'S') {
				h1.getGun()->setBullets(h1.getGun()->getBullets() - 1);
				map[p.x][i] = Object('O');
			}
		}
	}
	for (int i = p.y + 1; i <= p.y + range; ++i) {
		if (i >= 0 && i < 15) {
			if (map[p.x][i].getType() == 'S') {
				h1.getGun()->setBullets(h1.getGun()->getBullets() - 1);
				map[p.y][i] = Object('O');
			}
		}
	}
	for (int i = p.x - 1; i >= p.y - range; --i) {
		if (i >= 0 && i < 15) {
			if (map[i][p.y].getType() == 'S') {
				h1.getGun()->setBullets(h1.getGun()->getBullets() - 1);
				map[i][p.y] = Object('O');
			}
		}
	}
}
