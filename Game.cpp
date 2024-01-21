#include <iostream>
#include "Game.hpp"
#include "Object.hpp"
#include "Potion.hpp"
#include "Ammo.hpp"
#include "TankMonster.hpp"
#include "GhostMonster.hpp"
#include "Bazooka.hpp"
#include "Rifle.hpp"
#include "Pistol.hpp"
#include "Gun.hpp"
#include "DemolitionHero.hpp"
#include "Hero.hpp"
#include "MedicHero.hpp"
#include "Monster.hpp"
#include "Item.hpp"
#include <ctime>
#include <cstdlib>
using namespace std;

int Game::round = 0;

Game::Game():Object('G'){
	rows = 15;
	columns = 15;
}

Game::Game(int rows, int columns, Object** grid, Hero hero):Object('G'){
	this->rows = rows;
	this->columns = columns;
	this->grid = grid;
	this->hero = hero;
}

int Game::getColumns() const {
	return columns;
}

void Game::setColumns(int columns) {
	this->columns = columns;
}


int Game::getRows() const {
	return rows;
}

Object**& Game::getGrid() {
	return grid;
}

void Game::setGrid(Object **&grid) {
	this->grid = grid;
}

Hero& Game::getHero(){
	return hero;
}

void Game::setHero(const Hero &hero) {
	this->hero = hero;
}

void Game::setRows(int rows) {
	this->rows = rows;
}

Game::~Game() {
    for (int i = 0; i < rows; ++i) {
        delete[] grid[i];
    }
	delete[] grid;
}

void Game::move(Hero& h1 , char direction){
	Point p = h1.getPosition();
	Point p1 = h1.getPosition();
	switch (direction) {
	case 's':case 'S':
		p.x++;
		break;
	case 'a':case 'A':
		p.y--;
		break;
	case 'd':case 'D':
		p.y++;
		break;
	case 'w':case 'W':
		p.x--;
		break;
	}
	if (p.x < 0 || p.y < 0 || p.x > rows || p.y > columns){
		cout<<"You cannot move outside the borders of the grid";
		return;
	}
	else if(grid[p.x][p.y].getType() == 'A'){
		h1 = h1 + static_cast<Ammo&>(grid[p.x][p.y]);
		grid[p.x][p.y] = h1;
		h1.setPosition(p);
		grid[p1.x][p1.y] = Object('O');
	}else if(grid[p.x][p.y].getType() == 'N'){
		h1 = h1 + static_cast<Potion&>(grid[p.x][p.y]);
		grid[p.x][p.y] = h1;
		h1.setPosition(p);
		grid[p1.x][p1.y] = Object('O');
	}else if(grid[p.x][p.y].getType() == 'T' || grid[p.x][p.y].getType() == 'h'){
		h1 = h1 - static_cast<Monster&>(grid[p.x][p.y]);
	}else{
		grid[p.x][p.y] = h1;
		h1.setPosition(p);
		grid[p1.x][p1.y] = Object('O');
	}
}

int Game::checkGameOver() {

    if (hero.getHp()<= 0)
        return 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (grid[i][j].getType() == 'T' || grid[i][j].getType() == 'h') {
                return -1;
            }
        }
    }
    return 1;
}

void Game::updateMap() {
    system("clear");
    round ++;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (grid[i][j].getType() == 'T' || grid[i][j].getType() == 'h') {
                Monster& monster = static_cast<Monster&>(grid[i][j]);
                if (monster.getHp() <= 0) {
                    grid[i][j] = Object('O');
                }
            }
        }
    }
    if (round % 3 == 0) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (grid[i][j].getType() == 'h') {
                    GhostMonster& ghost = static_cast<GhostMonster&>(grid[i][j]);
                    ghost.setIsVisble(false);
                    ghost.setType('O');
                }
            }
        }
    }
    if (round % 3 == 1) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (grid[i][j].getType() == 'h') {
                    GhostMonster& ghost = static_cast<GhostMonster&>(grid[i][j]);
                    ghost.setIsVisble(true);
                    ghost.setType('h');
                }
            }
        }
    }
    if (round % 20 == 0) {
        respawnMonster('T');
        respawnMonster('h');
    }
    showMap();
}

void Game::respawnMonster(char monsterType) {
    int x, y;
    do {
        x = rand() % rows;
        y = rand() % columns;
    } while (grid[x][y].getType() != 'O');

    Point p = {x, y};
    if (monsterType == 'S') {
        int shild = 10;
        grid[x][y] = *(new TankMonster(shild, "RespawnedTankMonster", 100, p));
    } else if (monsterType == 'h') {
        grid[x][y] = *(new GhostMonster("RespawnedGhostMonster", 100, p));
    }
}

void Game::FireGun(char direction) {
    if (hero.getGun()->getBullets() < 1) {
        cout << "You do not have ammo" << std::endl;
        return;
    }
    hero.getGun()->setBullets(hero.getGun()->getBullets() - 1);
    int r = 0;
    if (dynamic_cast<Bazooka*>(hero.getGun()) != nullptr) {
        r = dynamic_cast<Bazooka*>(hero.getGun())->getRange();
    } else if (dynamic_cast<Rifle*>(hero.getGun()) != nullptr) {
        r = dynamic_cast<Rifle*>(hero.getGun())->getRange();
    } else if (dynamic_cast<Pistol*>(hero.getGun()) != nullptr) {
        r = dynamic_cast<Pistol*>(hero.getGun())->getRange();
    }
    Point p = hero.getPosition();
    Point t = p;
    for (int i = 0; i < r; ++i) {
        switch (direction) {
            case 's':
                t.x++;
                break;
            case 'a':
                t.y--;
                break;
            case 'd':
                t.y++;
                break;
            case 'w':
                t.x--;
                break;
        }
        if (t.x >= 0 && t.x < rows && t.y >= 0 && t.y < columns) {
            if (grid[t.x][t.y].getType() == 'T' || grid[t.x][t.y].getType() == 'h') {
            	(static_cast<Monster&>(grid[t.x][t.y])).setHp((static_cast<Monster&>(grid[t.x][t.y])).getHp() - hero.getGun()->getDmgamount());
                cout << "Shot " << hero.getGun()->getName() << " at position (" << t.x << ", " << t.y << ")." << endl;
                return;
            }
        }
    }
}

void Game:: useGunSpecial(){
	if(hero.getGun()->getType() == 'B'){
		if(hero.isStandingInDiagonal()){
			(static_cast<Bazooka&>(*hero.getGun())).useSpecial(hero, grid);
		}else{
			cout << "Invalid action";
		}
	}else if(hero.getGun()->getType() == 'L'){
		if(hero.getGun()->getBullets() > 4){
			(static_cast<Pistol&>(*hero.getGun())).useSpecial(hero, grid);
		}else{
			cout << "Invalid action";
		}
	}else{
		if(hero.getGun()->getBullets() > 3){
			(static_cast<Rifle&>(*hero.getGun())).useSpecial(hero, grid);
		}else{
			cout << "Invalid action";
		}
	}
}

Object** Game::GenerateMap(){
	grid = new Object*[rows];
	for (int i = 0; i < rows; ++i) {
	    grid[i] = new Object[columns];
	}
//	setting Hero location
	grid[0][0] = hero;
//	new Potions
	for(int i = 0; i < 5; i++){
		int x, y;
		do{
			x = (int) rand() % 14;
			y = (int) rand() % 14;
		}while(grid[x][y].getType() != 'O');
		int z = (int) 10 + rand() % 50;
		grid[x][y] = *(new Potion(z));
	}
//	new Ammos
	for(int i = 0; i < 10; i++){
		int x, y;
		do{
			x = (int) rand() % 14;
			y = (int) rand() % 14;
		}while(grid[x][y].getType() != 'O');
		int z = (int) 5 + rand() % 20;
		grid[x][y] = *(new Ammo(z));
	}
//	new Trank monsters
	for(int i = 0; i < 5; i++){
		int x, y;
		do{
			x = (int) rand() % 14;
			y = (int) rand() % 14;
		}while(grid[x][y].getType() != 'O');
		int z = (int) (6 + rand() % 15) * 10;
		Point p = {x, y};
		grid[x][y] = *(new TankMonster(10, "TankMonster " + i, z, p));
	}
//	new Ghost monsters
	for(int i = 0; i < 5; i++){
		int x, y;
		do{
			x = (int) rand() % 14;
			y = (int) rand() % 14;
		}while(grid[x][y].getType() != 'O');
		int z = (int) (6 + rand() % 15) * 10;
		Point p = {x, y};
		grid[x][y] = *(new GhostMonster("GhostMonster " + i, z, p));
	}
	return grid;
}

void Game::showMap(){
//	cout the generate map function
	string map[rows][columns];
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			if(grid[i][j].getType() != 'O')
				map[i][j] = grid[i][j].getType();
			else
				map[i][j] = ".";
		}
	}
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void Game::startGame(){
	cout << "Please enter M for Medic Hero or D for Demolition Hero: ";
	char c;
	cin >> c;
	while(c != 'D' && c != 'M'){
		cout << endl << "INVALID INPUT. Please enter M for Medic Hero or D for Demolition Hero: ";
		cin >> c;
	}
	cout<< endl << "Please enter Gun type, B for Bazooka, L for Pistol and R for Rifle: ";
	char c1;
	cin >> c1;
	while(c1 != 'B' && c1 != 'L' && c1 != 'R'){
		cout << endl << "INVALID INPUT. Please enter Gun type, B for Bazooka, L for Pistol and R for Rifle: ";
		cin >> c1;
	}
	Hero h;
	Point position = {0,0};
	Gun* g;
	if(c == 'D'){
		cout<< endl << "Please enter second Gun type, B for Bazooka, L for Pistol and R for Rifle: ";
		char c2;
		cin >> c2;
		while(c2 != 'B' && c2 != 'L' && c2 != 'R'){
			cout << endl << "INVALID INPUT. Please enter Gun type, B for Bazooka, L for Pistol and R for Rifle: ";
			cin >> c2;
		}
		Gun* g1;
		if(c1 == 'B'){
			g = new Bazooka;
			if(c2 == 'B'){
				g1 = new Bazooka;
			}else if(c2 == 'L'){
				g1 = new Pistol;
			}else{
				g1 = new Rifle;
			}
		}else if(c1 == 'L'){
			g = new Pistol;
			if(c2 == 'B'){
				g1 = new Bazooka;
			}else if(c2 == 'L'){
				g1 = new Pistol;
			}else{
				g1 = new Rifle;
			}
		}else{
			g = new Rifle;
			if(c2 == 'B'){
				g1 = new Bazooka;
			}else if(c2 == 'L'){
				g1 = new Pistol;
			}else{
				g1 = new Rifle;
			}
		}
		h = *(new DemolitionHero(*g1, g, 100, position));
	}
	else{
		if(c1 == 'B'){
			g = new Bazooka;
		}else if(c1 == 'L'){
			g = new Pistol;
		}else{
			g = new Rifle;
		}
		h = *(new MedicHero(50, g, 100, position));
	}
	hero = h;
	grid = this->GenerateMap();
	this->showMap();
	cout << hero;
	while (checkGameOver() == -1) {
		cout << "Current Round: " << round << endl;
		cout << "Enter action; M for Move, S for Shoot, G for Use Gun Special, H for Use Hero Special or E for End The Game. ";
		char action;
		cin >> action;
		switch (action) {
			case 'M':
				char d;
				cout << "Enter move direction; W for Up, A for Left, S for Down or D for Right. ";
				cin >> d;
				move(hero, d);
				break;
			case 'S':
				char s;
				cout << "Enter shoot direction; W for Up, A for Left, S for Down or D for Right. ";
				cin >> s;
				FireGun(s);
				break;
			case 'G':
				useGunSpecial();
				break;
			case 'H':
				hero.useSpecial();
				break;
			case 'E':
				cout << "Game over." << endl;
				return;
			default:
				cout << "Invalid action. Please Enter action; M for Move, S for Shoot, G for Use Gun Special, H for Use Hero Special, E for End The Game." << endl;
		}
		updateMap();
	}if(checkGameOver() == 1)
		cout << "Game Over, you won." << endl;
	else
		cout << "Game Over, you lost." << endl;

}

int main(){
	cout << "Hello, Welcome to our Game." << endl;
	srand(time(NULL));
	Game g;
	g.startGame();
	return 0;
}

