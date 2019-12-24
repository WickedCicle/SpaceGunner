#include <iostream>
#include "World.h"
#include "ConsoleSetUp.h"
#include "Actor.h"
#include "Bullet.h"
#include "Ship.h"
#include "KeyEvent.h"
#include "Timer.h"
#include <chrono>
#include "Menu.h"
#include "Enemy.h"

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	RemoveScrollBox();
	FullScreen();
	HideCursor();
	//LucidaConnect();
	srand(time(NULL));

	bool EscapePressed = false;
	bool Win = false;
	int Score = 0;

	string NickName;
	NickName = WriteName();
	Sleep(200);

	Settings_Args SetArgs;
	MainMenu(SetArgs);

	SetConsoleOutputCP(65001);
	UnicodeConnect();

	Timer Move;
	Timer Shoot;
	Timer Enemy_Move;
	Timer Bullets_Move;
	Timer Enemy_Bullets_Move;
	Timer Enemy_Fire_Time;

	clock_t start;
	float result = 0;

	FirstEnemyPos EnemyPos;
	World map(SetArgs.length, SetArgs.width);
	vector<Enemy> enemies;
	vector<Bullet> bullets;
	vector<Bullet> enemy_bullets;
	Ship Hero(0, (int)SetArgs.width/2, SetArgs.Hero_health);

	map.CreateMap(Hero);
	map.CreateEnemies(enemies, SetArgs.Enemy_health, EnemyPos);

	while (!Hero.get_Is_dead() && !Win) {
		start = clock();

		HideCursor();
		KeyState(Hero, bullets, map, Move, Shoot, EscapePressed);

		map.DrawMap(EscapePressed);
		map.DrawBullets(bullets, enemy_bullets);
		map.MoveBullets(bullets, enemy_bullets, Bullets_Move, Enemy_Bullets_Move);
		map.checkbullets(Hero, bullets, enemies, enemy_bullets, SetArgs, Score);
		map.Move_Enemies(enemies, Enemy_Move, EnemyPos, SetArgs, Win, Hero);
		map.Enemy_Fire(enemy_bullets, EnemyPos, Enemy_Fire_Time);
		result = clock() -  start;

		Move.add_time(result);
		Shoot.add_time(result);
		Enemy_Move.add_time(result);
		Bullets_Move.add_time(result);
		Enemy_Bullets_Move.add_time(result);
		Enemy_Fire_Time.add_time(result);
	}

	system("cls");

	if (Win) {
		wcout << "You Win\n";
		AddToFile(NickName, Score, FilePath);
	}
	else {
		wcout << "You Lose\n";;
	}

	Sleep(2500);

	system("Pause");
	return 0;
}