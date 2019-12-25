#include <iostream>
#include "Ship.h"
#include "Enemy.h"
#include "ConsoleSetUp.h"
#include "Timer.h"
#include "Menu.h"

using namespace std;

#ifndef WORLD_H
#define WORLD_H

// перечисление хранит символы объектов на карте
enum map_symbols {
	border = L'#',
	space = L' ',
	hero = L'ϖ',
	enemy = L'¶',
	hero_bullet = L'⁍',
	enemy_bullet = L'⁌'
};

// класс хранящий двумерный массив(карту) и производящий над ней изменения
class World {
private:
	int length; // длина карты
	int width; // ширина карты
	wchar_t** map; // двумерный массив(карта)
public:

	World() {};
	World(int new_length, int new_width);

	int get_length();
	int get_width();

	void CreateMap(Ship Hero); // отрисовывает первоначальную карту
	void CreateEnemies(vector<Enemy> &enemies, int Enemy_health, FirstEnemyPos &EnemyPos); // создаёт на карте врагов и записывает в вектор
	void DrawMap(bool &EscapePressed, Ship &Hero, vector<Enemy> &enemies, int &Score); // отрисовка карты
	void DrawBullets(vector<Bullet> &bullets, vector<Bullet> &enemy_bullets); // отрисовывает пули на карте
	void MoveBullets(vector<Bullet> &bullets, vector<Bullet> &enemy_bullets, Timer& Bullets_Move); // перемещает пуль на карте
	void Move_Enemies(vector<Enemy> &enemies, Timer &Enemy_Move, FirstEnemyPos &EnemyPos, Settings_Args &SetArgs, bool &Win, Ship &Hero); // перемещает врагов на карте
	void Enemy_Fire(vector<Bullet> &enemy_bullets, FirstEnemyPos &EnemyPos); // добавляет в вектор пули врагов при их стрельбе
	void checkbullets(Ship &Hero, vector<Bullet> &bullets, vector<Enemy> &enemies, vector<Bullet> &enemy_bullets, Settings_Args &SetArgs, int &Score); // првоерка на попадание или вылет за границы карты
	void SetMapSymbol(int x, int y, wchar_t symbol); // устанавливает на позиции x,y карты символ symbol
};
#endif // !WORLD_H
