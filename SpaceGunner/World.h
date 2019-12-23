#include <iostream>
#include "Ship.h"
#include "Enemy.h"
#include "ConsoleSetUp.h"
#include "Timer.h"

using namespace std;

#ifndef WORLD_H
#define WORLD_H

enum map_symbols {
	border = L'#',
	space = L' ',
	hero = L'ϖ',
	enemy = L'¶',
	hero_bullet = L'⁍',
	enemy_bullet = L'⁌'
};

class World {
private:
	int length;
	int width;
	wchar_t** map;
public:

	World() {};
	World(int new_length, int new_width);

	int get_length();
	int get_width();

	void CreateMap(Ship Hero);
	void CreateEnemies(vector<Enemy> &enemies, int Enemy_health);
	void DrawMap();
	void DrawBullets(vector<Bullet> &bullets);
	void MoveBullets(vector<Bullet> &bullets, Timer& Bullets_Move);
	void Move_Enemies(vector<Enemy> &enemies, Timer &Enemy_Move);
	//void checkbullets(vector<Bullet> &bullets, vector<Ship> &enemies);
	void checkbullets(vector<Bullet> &bullets, vector<Enemy> &enemies);
	void SetMapSymbol(int x, int y, wchar_t symbol);
	//wchar_t GetMapSymbol(int x, int y);
};
#endif // !WORLD_H
