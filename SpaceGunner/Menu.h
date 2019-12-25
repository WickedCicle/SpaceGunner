#include "ScoreBoard.h"
#include <Windows.h>
#include <algorithm>

#ifndef MENU_H
#define MENU_H

// структура хранит настройки карты, которые пользователь может поменять
struct Settings_Args {
	int length = 60;
	int width = 25;
	int Hero_health = 3;
	int Enemy_health = 1;
};

void MainMenu(Settings_Args &SetArgs); // главное меню, запускается во время запуска приложения
void SettingsMenu(Settings_Args &SetArgs); // меню настроек
void HelpMenu(); // меню, показывающее управление
void LeaderBoard(bool &IsOpened); // таблица лидеров
void EscMenu(); // пауза

#endif
