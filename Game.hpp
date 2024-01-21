#ifndef GAME_HPP_
#define GAME_HPP_
#include "Object.hpp"
#include "Hero.hpp"

class Game : public Object{
	private:
		int rows;
		int columns;
		Object** grid;
		Hero hero;
	public:
		Game();
		Game(int rows, int columns, Object** grid, Hero hero);
		~Game();
		Object** GenerateMap();
		void showMap();
		void startGame();
		int getColumns() const;
		void setColumns(int columns);
		int getRows() const;
		void setRows(int rows);
		Object**& getGrid();
		void setGrid(Object **&grid);
		Hero& getHero();
		void setHero(const Hero &hero);
		static int round;
		void move(Hero& h1 , char direction);
		void updateMap();
		int checkGameOver();
		void respawnMonster(char monsterType);
		void FireGun(char direction);
		void useGunSpecial();
};

#endif /* GAME_H_ */
