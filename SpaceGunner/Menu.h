#include "ScoreBoard.h"
#include <Windows.h>
#include <algorithm>

#ifndef MENU_H
#define MENU_H

struct Settings_Args {
	int length = 60;
	int width = 25;
	int Hero_health = 3;
	int Enemy_health = 1;
};

void MainMenu(Settings_Args &SetArgs);
void SettingsMenu(Settings_Args &SetArgs);
void HelpMenu();
void LeaderBoard(bool &IsOpened);
void EscMenu();

#endif
