#include "ScoreBoard.h"
#include <Windows.h>
#include <algorithm>

#ifndef MENU_H
#define MENU_H

void MainMenu(int &length, int &width, int &Hero_health, int &Enemy_health);
void SettingsMenu(int &length, int &width, int &Hero_health, int &Enemy_health);
void HelpMenu();
void LeaderBoard(bool &IsOpened);

#endif
