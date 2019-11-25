#include <iostream>
#include "World.h"
#include "ConsoleSetUp.h"
#include "Actor.h"
#include "Bullet.h"
#include "Ship.h"
#include "KeyEvent.h"
#include "Timer.h"
#include <chrono>
#include "Sounds.h"
#include <thread>

using namespace std;

void MainMenu(int &length, int &width);
void SettingMenu(int &length, int &width);

int main() {
	SetConsoleOutputCP(1251);

	int length = 30;
	int width = 15;

	MainMenu(length, width);

	SetConsoleOutputCP(65001);
	UnicodeConnect();

	Timer Move;
	Move.set_time(0);
	Timer Shoot;
	Shoot.set_time(0);

	clock_t start;
	float result = 0;

	World map(length, width);
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

void MainMenu(int &length, int &width) {
	int switcher = 0;
	wcout << "<<Играть>>\n";
	wcout << "Настройки\n";

	while (true) {
		if (GetKeyState('W') < 0) {
			Sleep(250);
			system("cls");
			Sound("Sounds\\MenuChange.wav");
			if (switcher == 0) {
				wcout << "Играть\n";
				wcout << "<<Настройки>>\n";
				switcher = 1;
				continue;
			}
			if (switcher == 1) {
				wcout << "<<Играть>>\n";
				wcout << "Настройки\n";
				switcher = 0;
				continue;
			}
		}
		if (GetKeyState('S') < 0) {
			Sleep(250);
			system("cls");
			Sound("Sounds\\MenuChange.wav");
			if (switcher == 0) {
				wcout << "Играть\n";
				wcout << "<<Настройки>>\n";
				switcher = 1;
				continue;
			}
			if (switcher == 1) {
				wcout << "<<Играть>>\n";
				wcout << "Настройки\n";
				switcher = 0;
				continue;
			}
		}

		if (GetKeyState(VK_RETURN) < 0) {
			if (switcher == 0) {
				break;
			}
			if (switcher == 1) {
				system("cls");
				SettingMenu(length, width);
				system("cls");
				wcout << "<<Играть>>\n";
				wcout << "Настройки\n";
				switcher = 0;
				Sleep(250);
			}
		}
	}
}

void SettingMenu(int &length, int &width) {
	int NextMenu = 0;
	int switcher = 0;
	wcout << "<< Длина поля >> = " << length << endl;
	wcout << "Ширина поля = " << width << endl;
	wcout << "Назад" << endl;

	while (!NextMenu) {
		if (GetKeyState('W') < 0) {
			Sleep(250);
			system("cls");
			Sound("Sounds\\MenuChange.wav");
			if (switcher == 0) {
				wcout << "Длина поля = " << length << endl;
				wcout << "Ширина поля = " << width << endl;
				wcout << "<< Назад >>" << endl;
				switcher = 2;
				continue;
			}
			if (switcher == 1) {
				wcout << "<< Длина поля >> = " << length << endl;
				wcout << "Ширина поля = " << width << endl;
				wcout << "Назад" << endl;
				switcher = 0;
				continue;
			}
			if (switcher == 2) {
				wcout << "Длина поля = " << length << endl;
				wcout << "<< Ширина поля >> = " << width << endl;
				wcout << "Назад" << endl;
				switcher = 1;
				continue;
			}
		}
		if (GetKeyState('S') < 0) {
			Sleep(250);
			system("cls");
			Sound("Sounds\\MenuChange.wav");
			if (switcher == 0) {
				wcout << "Длина поля = " << length << endl;
				wcout << "<< Ширина поля >> = " << width << endl;
				wcout << "Назад" << endl;
				switcher = 1;
				continue;
			}
			if (switcher == 1) {
				wcout << "Длина поля = " << length << endl;
				wcout << "Ширина поля = " << width << endl;
				wcout << "<< Назад >>" << endl;
				switcher = 2;
				continue;
			}
			if (switcher == 2) {
				wcout << "<< Длина поля >> = " << length << endl;
				wcout << "Ширина поля = " << width << endl;
				wcout << "Назад" << endl;
				switcher = 0;
				continue;
			}
		}

		if (GetKeyState(VK_LEFT) < 0) {
			Sleep(125);
			if (switcher == 0 && length > 30) {
				system("cls");
				length--;
				wcout << "<< Длина поля >> = " << length << endl;
				wcout << "Ширина поля = " << width << endl;
				wcout << "Назад" << endl;
				continue;
			}
			else if (switcher == 1 && width > 15) {
				system("cls");
				width--;
				wcout << "Длина поля = " << length << endl;
				wcout << "<< Ширина поля >> = " << width << endl;
				wcout << "Назад" << endl;
				continue;
			}
		}
		if (GetKeyState(VK_RIGHT) < 0) {
			Sleep(125);
			if (switcher == 0 && length < 70) {
				system("cls");
				length++;
				wcout << "<< Длина поля >> = " << length << endl;
				wcout << "Ширина поля = " << width << endl;
				wcout << "Назад" << endl;
				continue;
			}
			else if (switcher == 1 && width < 30) {
				system("cls");
				width++;
				wcout << "Длина поля = " << length << endl;
				wcout << "<< Ширина поля >> = " << width << endl;
				wcout << "Назад" << endl;
				continue;
			}
		}

		if (GetKeyState(VK_RETURN) < 0) {
			if (switcher == 2) {
				break;
			}
		}
	}
}