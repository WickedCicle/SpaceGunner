#include <iostream>
#include "Ship.h"
#include "Enemy.h"
#include "ConsoleSetUp.h"
#include "Timer.h"
#include "Menu.h"

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
	void CreateEnemies(vector<Enemy> &enemies, int Enemy_health, FirstEnemyPos &EnemyPos);
	void DrawMap(bool &EscapePressed);
	void DrawBullets(vector<Bullet> &bullets, vector<Bullet> &enemy_bullets);
	void MoveBullets(vector<Bullet> &bullets, vector<Bullet> &enemy_bullets, Timer& Bullets_Move, Timer &Enemy_Bullets_Move);
	void Move_Enemies(vector<Enemy> &enemies, Timer &Enemy_Move, FirstEnemyPos &EnemyPos, Settings_Args &SetArgs, bool &Win, Ship &Hero);
	void Enemy_Fire(vector<Bullet> &enemy_bullets, FirstEnemyPos &EnemyPos, Timer &EnemyFire);
	void checkbullets(Ship &Hero, vector<Bullet> &bullets, vector<Enemy> &enemies, vector<Bullet> &enemy_bullets, Settings_Args &SetArgs, int &Score);
	void SetMapSymbol(int x, int y, wchar_t symbol);
};
#endif // !WORLD_H
