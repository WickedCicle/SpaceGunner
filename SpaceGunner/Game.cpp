#include <iostream>
#include "World.h"
#include "ConsoleSetUp.h"
#include "Actor.h"
#include "Bullet.h"
#include "Ship.h"
#include "KeyEvent.h"
#include "Timer.h"
#include <chrono>
#include <thread>
#include "Menu.h"
#include "Enemy.h"

using namespace std;

int main() {
	HideCursor();
	SetConsoleOutputCP(1251);

	bool Win = false;

	string NickName;

	int length = 30;
	int width = 15;
	int Hero_health = 3;
	int Eneny_health = 1;

	MainMenu(length, width, Hero_health, Eneny_health);

	NickName = WriteName();

	SetConsoleOutputCP(65001);
	UnicodeConnect();

	Timer Move;
	Timer Shoot;
	Timer Enemy_Move;
	Timer Bullets_Move;

	clock_t start;
	float result = 0;

	World map(length, width);
	vector<Enemy> enemies;
	vector<Bullet> bullets;
	Ship Hero(0, (int)width/2, Hero_health);

	map.CreateMap(Hero);
	map.CreateEnemies(enemies, Eneny_health);

	srand(time(NULL));

	while (!Hero.get_Is_dead() && !Win) {
		start = clock();

		HideCursor();
		KeyState(Hero, bullets, map, Move, Shoot);

		map.DrawMap();
		map.DrawBullets(bullets);
		map.MoveBullets(bullets, Bullets_Move);
		map.checkbullets(bullets, enemies);
		map.Move_Enemies(enemies, Enemy_Move);
		result = clock() -  start;

		Move.add_time(result);
		Shoot.add_time(result);
		Enemy_Move.add_time(result);
		Bullets_Move.add_time(result);

		//Win = true;
		//Hero.DestroyShip();
	}

	system("cls");

	wcout << "Win\n";

	if (Win) {
		wcout << "You Win\n";
		AddToFile(NickName, 100, FilePath);
	}
	else {
		wcout << "You Lose\n";;
	}

	system("Pause");
	return 0;
}