#include "Bazooka.hpp"
#include "Gun.hpp"
#include "Hero.hpp"
#include <iostream>
using namespace std;

Bazooka::Bazooka():Gun("Bazooka",4, 150, 8){
	this->setType('B');
}

Bazooka::~Bazooka(){

}

void Bazooka::useSpecial(Hero& h1, Object** map){
	Point p = h1.getPosition();
	for (int i = 0; i < 15; ++i) {
		int j = (p.x + p.y) - i;
		if (j >= 0 && j < 15) {
			if (map[i][j].getType() == 'S') {
				map[i][j] = Object('O');
			}
		}
	}
	for (int i = 0; i < 15; ++i) {
		int j = (p.y - p.x) + i;
		if (j >= 0 && j < 15) {
			if (map[i][j].getType() == 'S') {
				map[i][j] = Object('O');
			}
		}
	}

}
