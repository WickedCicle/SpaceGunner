#include <iostream>
#include "World.h"
#include "ConsoleSetUp.h"
#include "Actor.h"
#include "Bullet.h"
#include "Ship.h"
#include "KeyEvent.h"
#include "Timer.h"
#include <chrono>

using namespace std;

int main() {
	SetConsoleOutputCP(65001);
	UnicodeConnect();

	Timer Move;
	Move.set_time(0);
	Timer Shoot;
	Shoot.set_time(0);

	clock_t start;
	float result = 0;

	World map(60, 30);
	vector<Bullet> bullets;
	vector<Ship> enemies;
	Ship Hero(7, 7, 100);

	map.CreateMap(Hero);

	srand(time(NULL));

	enemies.push_back(Ship((rand() % map.get_length() / 2) + 20, map.get_width() / 2, 20));

	while (!Hero.get_Is_dead()) {
		start = clock();

		HideCursor();
		KeyState(Hero, bullets, map, Move, Shoot);

		/*for (int i = 0; i < 8; i++) {
			for (int j = enemies.size(); j < 8; j++) {
				enemies.push_back(Ship((rand() % (map.get_length() / 2)) + (map.get_length() / 2), (rand() % (map.get_width() - 4)) + 2, 20));
			}
			map.SetMapSymbol(enemies[i].get_x_pos(), enemies[i].get_y_pos(), map_symbols::enemy);
		}*/

		/*for (int i = 0; i < 6; i++) {
			for (int j = enemies.size(); j < 6; j++) {
				if (enemies[j - 1].get_y_pos() > 3 && enemies[j - 1].get_x_pos() + 1 < map.get_length()) {
					enemies.push_back(Ship(enemies[j - 1].get_x_pos() + 1, enemies[j - 1].get_y_pos() - 1, 5));
				}
				else {
					enemies.push_back(Ship(enemies[0].get_x_pos() - j, enemies[0].get_y_pos() + j, 5));
				}
			}
			map.SetMapSymbol(enemies[i].get_x_pos(), enemies[i].get_y_pos(), map_symbols::enemy);
		}*/

		map.DrawMap();
		map.DrawBullets(bullets);
		map.MoveBullets(bullets);
		map.bullet_out_of_range(bullets);
 		map.checkbullets(bullets, enemies);

		result = clock() -  start;

		Move.add_time(result);
		Shoot.add_time(result);
	}

	system("Pause");
	return 0;
}