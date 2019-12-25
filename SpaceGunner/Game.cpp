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
	FullScreen();
	RemoveScrollBox();
	HideCursor();
	srand(time(NULL));

	bool EscapePressed = false; // переменная для хранения, нажат ли Esc
	bool Win = false; // переменная для хранения победы пользователя
	int Score = 0; // счёт игрока

	string NickName; // имя игрока
	NickName = WriteName();
	Sleep(200);

	Settings_Args SetArgs; // структура, хранящая настройки карты
	MainMenu(SetArgs); // главное меню

	SetConsoleOutputCP(65001);
	UnicodeConnect();

	Timer Move; // таймер на перемещение героя
	Timer Shoot; // таймер на стрельбу героя
	Timer Enemy_Move; // таймер на перемещение врагов
	Timer Bullets_Move; // таймер на полёт пуль 

	clock_t start;
	float result = 0;

	FirstEnemyPos EnemyPos;
	World map(SetArgs.length, SetArgs.width);
	vector<Enemy> enemies; // вектор хранящий врагов
	vector<Bullet> bullets; // вектор хранящий пули героя
	vector<Bullet> enemy_bullets; // вектор хранящий пули врагов
	Ship Hero(0, (int)SetArgs.width/2, SetArgs.Hero_health); // создания корабля героя

	map.CreateMap(Hero);
	map.CreateEnemies(enemies, SetArgs.Enemy_health, EnemyPos);

	while (!Hero.get_Is_dead() && !Win) {
		start = clock(); // время начала итерации

		HideCursor();
		KeyState(Hero, bullets, map, Move, Shoot, EscapePressed); // проверка нажатий клавиш клавиатуры

		map.DrawMap(EscapePressed, Hero, enemies, Score);
		map.DrawBullets(bullets, enemy_bullets);
		map.MoveBullets(bullets, enemy_bullets, Bullets_Move);
		map.checkbullets(Hero, bullets, enemies, enemy_bullets, SetArgs, Score);
		map.Move_Enemies(enemies, Enemy_Move, EnemyPos, SetArgs, Win, Hero);
		map.Enemy_Fire(enemy_bullets, EnemyPos);
		result = clock() -  start; // время конца итерации

		// добавления времени работы итерации к таймерам
		Move.add_time(result);
		Shoot.add_time(result);
		Enemy_Move.add_time(result);
		Bullets_Move.add_time(result);
	}

	system("cls");

	// если пользователь победил
	if (Win) {
		wcout << L"Победа\n";
		wcout << L"Ваш счёт: " << Score << "\n";
		AddToFile(NickName, Score, FilePath); // добавляем его результат в файл
	}
	else {
		wcout << L"Поражение\n";;
	}

	Sleep(2500);

	system("Pause");
	return 0;
}