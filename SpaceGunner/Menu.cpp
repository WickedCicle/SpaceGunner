#include "Menu.h"

using namespace std;

enum MainMenu {
	Play = 0,
	Settings = 1,
	Help = 2,
	ScoreBoard = 3,
	Exit = 4
};

enum SettingsMenu {
	Length = 0,
	Width = 1,
	Hero_Health = 2,
	Enemy_Health = 3,
	Defaults = 4,
	Back = 5
};

void MainMenu(int &length, int &width, int &Hero_health, int &Enemy_health) {
	bool IsLeaderBoardOpened = false;
	int switcher = MainMenu::Play;
	wcout << "<< Играть >>\n";
	wcout << "Настройки\n";
	wcout << "Как играть\n";
	wcout << "Таблица лидеров\n";
	wcout << "Выход\n";

	while (true) {
		if (GetKeyState('W') < 0) {
			Sleep(250);
			system("cls");
			if (switcher == MainMenu::Play) {
				wcout << "Играть\n";
				wcout << "Настройки\n";
				wcout << "Как играть\n";
				wcout << "Таблица лидеров\n";
				wcout << "<< Выход >>\n";
				switcher = MainMenu::Exit;
				continue;
			}
			else if (switcher == MainMenu::Settings) {
				wcout << "<< Играть >>\n";
				wcout << "Настройки\n";
				wcout << "Как играть\n";
				wcout << "Таблица лидеров\n";
				wcout << "Выход\n";
				switcher = MainMenu::Play;
				continue;
			}
			else if (switcher == MainMenu::Help) {
				wcout << "Играть\n";
				wcout << "<< Настройки >>\n";
				wcout << "Как играть\n";
				wcout << "Таблица лидеров\n";
				wcout << "Выход\n";
				switcher = MainMenu::Settings;
				continue;
			}
			else if (switcher == MainMenu::ScoreBoard) {
				wcout << "Играть\n";
				wcout << "Настройки\n";
				wcout << "<< Как играть >>\n";
				wcout << "Таблица лидеров\n";
				wcout << "Выход\n";
				switcher = MainMenu::Help;
				continue;
			}
			else if (switcher == MainMenu::Exit) {
				wcout << "Играть\n";
				wcout << "Настройки\n";
				wcout << "Как играть\n";
				wcout << "<< Таблица лидеров >>\n";
				wcout << "Выход\n";
				switcher = MainMenu::ScoreBoard;
				continue;
			}
		}
		if (GetKeyState('S') < 0) {
			Sleep(250);
			system("cls");
			if (switcher == MainMenu::Play) {
				wcout << "Играть\n";
				wcout << "<< Настройки >>\n";
				wcout << "Как играть\n";
				wcout << "Таблица лидеров\n";
				wcout << "Выход\n";
				switcher = MainMenu::Settings;
				continue;
			}
			else if (switcher == MainMenu::Settings) {
				wcout << "Играть\n";
				wcout << "Настройки\n";
				wcout << "<< Как играть >>\n";
				wcout << "Таблица лидеров\n";
				wcout << "Выход\n";
				switcher = MainMenu::Help;
				continue;
			}
			else if (switcher == MainMenu::Help) {
				wcout << "Играть\n";
				wcout << "Настройки\n";
				wcout << "Как играть\n";
				wcout << "<< Таблица лидеров >>\n";
				wcout << "Выход\n";
				switcher = MainMenu::ScoreBoard;
				continue;
			}
			else if (switcher == MainMenu::ScoreBoard) {
				wcout << "Играть\n";
				wcout << "Настройки\n";
				wcout << "Как играть\n";
				wcout << "Таблица лидеров\n";
				wcout << "<< Выход >>\n";
				switcher = MainMenu::Exit;
				continue;
			}
			else if (switcher == MainMenu::Exit) {
				wcout << "<< Играть >>\n";
				wcout << "Настройки\n";
				wcout << "Как играть\n";
				wcout << "Таблица лидеров\n";
				wcout << "Выход\n";
				switcher = MainMenu::Play;
				continue;
			}
		}

		if (GetKeyState(VK_RETURN) < 0) {
			if (switcher == MainMenu::Play) {
				system("cls");
				break;
			}
			else if (switcher == MainMenu::Settings) {
				system("cls");
				SettingsMenu(length, width, Hero_health, Enemy_health);
				system("cls");
				wcout << "<< Играть >>\n";
				wcout << "Настройки\n";
				wcout << "Как играть\n";
				wcout << "Таблица лидеров\n";
				wcout << "Выход\n";
				switcher = MainMenu::Play;
				Sleep(250);
			}
			else if (switcher == MainMenu::Help) {
				system("cls");
				HelpMenu();
				system("cls");
				wcout << "<< Играть >>\n";
				wcout << "Настройки\n";
				wcout << "Как играть\n";
				wcout << "Таблица лидеров\n";
				wcout << "Выход\n";
				switcher = MainMenu::Play;
				Sleep(250);
			}
			else if (switcher == MainMenu::ScoreBoard) {
				system("cls");
				LeaderBoard(IsLeaderBoardOpened);
				system("cls");
				wcout << "<< Играть >>\n";
				wcout << "Настройки\n";
				wcout << "Как играть\n";
				wcout << "Таблица лидеров\n";
				wcout << "Выход\n";
				switcher = MainMenu::Play;
				Sleep(250);
			}
			else if (switcher == MainMenu::Exit) {
				ExitProcess(0);
			}
		}
	}
}

void SettingsMenu(int &length, int &width, int &Hero_health, int &Enemy_health) {
	int switcher = SettingsMenu::Length;
	wcout << "<< Длина поля >> = " << length << "\n";
	wcout << "Ширина поля = " << width << "\n";
	wcout << "Здоровье корабля = " << Hero_health << "\n";
	wcout << "Здоровье врагов = " << Enemy_health << "\n";
	wcout << "Установить значения по умолчанию" << "\n";
	wcout << "Назад\n";

	while (true) {
		if (GetKeyState('W') < 0) {
			Sleep(250);
			system("cls");
			if (switcher == SettingsMenu::Length) {
				wcout << "Длина поля = " << length << "\n";
				wcout << "Ширина поля = " << width << "\n";
				wcout << "Здоровье корабля = " << Hero_health << "\n";
				wcout << "Здоровье врагов = " << Enemy_health << "\n";
				wcout << "Установить значения по умолчанию" << "\n";
				wcout << "<< Назад >>" << "\n";
				switcher = SettingsMenu::Back;
				continue;
			}
			else if (switcher == SettingsMenu::Width) {
				wcout << "<< Длина поля >> = " << length << "\n";
				wcout << "Ширина поля = " << width << "\n";
				wcout << "Здоровье корабля = " << Hero_health << "\n";
				wcout << "Здоровье врагов = " << Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				switcher = SettingsMenu::Length;
				continue;
			}
			else if (switcher == SettingsMenu::Hero_Health) {
				wcout << "Длина поля = " << length << "\n";
				wcout << "<< Ширина поля >> = " << width << "\n";
				wcout << "Здоровье корабля = " << Hero_health << "\n";
				wcout << "Здоровье врагов = " << Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				switcher = SettingsMenu::Width;
				continue;
			}
			else if (switcher == SettingsMenu::Enemy_Health) {
				wcout << "Длина поля = " << length << "\n";
				wcout << "Ширина поля = " << width << "\n";
				wcout << "<< Здоровье корабля >> = " << Hero_health << "\n";
				wcout << "Здоровье врагов = " << Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				switcher = SettingsMenu::Hero_Health;
				continue;
			}
			else if (switcher == SettingsMenu::Defaults) {
				wcout << "Длина поля = " << length << "\n";
				wcout << "Ширина поля = " << width << "\n";
				wcout << "Здоровье корабля = " << Hero_health << "\n";
				wcout << "<< Здоровье врагов >> = " << Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				switcher = SettingsMenu::Enemy_Health;
				continue;
			}
			else if (switcher == SettingsMenu::Back) {
				wcout << "Длина поля = " << length << "\n";
				wcout << "Ширина поля = " << width << "\n";
				wcout << "Здоровье корабля = " << Hero_health << "\n";
				wcout << "Здоровье врагов = " << Enemy_health << "\n";
				wcout << "<< Установить значения по умолчанию >>\n";
				wcout << "Назад\n";
				switcher = SettingsMenu::Defaults;
				continue;
			}
		}
		if (GetKeyState('S') < 0) {
			Sleep(250);
			system("cls");
			if (switcher == SettingsMenu::Length) {
				wcout << "Длина поля = " << length << "\n";
				wcout << "<< Ширина поля >> = " << width << "\n";
				wcout << "Здоровье корабля = " << Hero_health << "\n";
				wcout << "Здоровье врагов = " << Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				switcher = SettingsMenu::Width;
				continue;
			}
			else if (switcher == SettingsMenu::Width) {
				wcout << "Длина поля = " << length << "\n";
				wcout << "Ширина поля = " << width << "\n";
				wcout << "<< Здоровье корабля >> = " << Hero_health << "\n";
				wcout << "Здоровье врагов = " << Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				switcher = SettingsMenu::Hero_Health;
				continue;
			}
			else if (switcher == SettingsMenu::Hero_Health) {
				wcout << "Длина поля = " << length << "\n";
				wcout << "Ширина поля = " << width << "\n";
				wcout << "Здоровье корабля = " << Hero_health << "\n";
				wcout << "<< Здоровье врагов >> = " << Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				switcher = SettingsMenu::Enemy_Health;
				continue;
			}
			else if (switcher == SettingsMenu::Enemy_Health) {
				wcout << "Длина поля = " << length << "\n";
				wcout << "Ширина поля = " << width << "\n";
				wcout << "Здоровье корабля = " << Hero_health << "\n";
				wcout << "Здоровье врагов = " << Enemy_health << "\n";
				wcout << "<< Установить значения по умолчанию >>\n";
				wcout << "Назад\n";
				switcher = SettingsMenu::Defaults;
				continue;
			}
			else if (switcher == SettingsMenu::Defaults) {
				wcout << "Длина поля = " << length << "\n";
				wcout << "Ширина поля = " << width << "\n";
				wcout << "Здоровье корабля = " << Hero_health << "\n";
				wcout << "Здоровье врагов = " << Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "<< Назад >>\n";
				switcher = SettingsMenu::Back;
				continue;
			}
			else if (switcher == SettingsMenu::Back) {
				wcout << "<< Длина поля >> = " << length << "\n";
				wcout << "Ширина поля = " << width << "\n";
				wcout << "Здоровье корабля = " << Hero_health << "\n";
				wcout << "Здоровье врагов = " << Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				switcher = SettingsMenu::Length;
				continue;
			}
		}

		if (GetKeyState(VK_LEFT) < 0) {
			Sleep(125);
			if (switcher == SettingsMenu::Length && length > 30) {
				system("cls");
				length--;
				wcout << "<< Длина поля >> = " << length << "\n";
				wcout << "Ширина поля = " << width << "\n";
				wcout << "Здоровье корабля = " << Hero_health << "\n";
				wcout << "Здоровье врагов = " << Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				continue;
			}
			else if (switcher == SettingsMenu::Width && width > 15) {
				system("cls");
				width--;
				wcout << "Длина поля = " << length << "\n";
				wcout << "<< Ширина поля >> = " << width << "\n";
				wcout << "Здоровье корабля = " << Hero_health << "\n";
				wcout << "Здоровье врагов = " << Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				continue;
			}
			else if (switcher == SettingsMenu::Hero_Health && Hero_health > 1) {
				system("cls");
				Hero_health--;
				wcout << "Длина поля = " << length << "\n";
				wcout << "Ширина поля = " << width << "\n";
				wcout << "<< Здоровье корабля >> = " << Hero_health << "\n";
				wcout << "Здоровье врагов = " << Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				continue;
			}
			else if (switcher == SettingsMenu::Enemy_Health && Enemy_health > 1) {
				system("cls");
				Enemy_health--;
				wcout << "Длина поля = " << length << "\n";
				wcout << "Ширина поля = " << width << "\n";
				wcout << "Здоровье корабля = " << Hero_health << "\n";
				wcout << "<< Здоровье врагов >> = " << Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				continue;
			}
		}
		if (GetKeyState(VK_RIGHT) < 0) {
			Sleep(125);
			if (switcher == SettingsMenu::Length && length < 70) {
				system("cls");
				length++;
				wcout << "<< Длина поля >> = " << length << "\n";
				wcout << "Ширина поля = " << width << "\n";
				wcout << "Здоровье корабля = " << Hero_health << "\n";
				wcout << "Здоровье врагов = " << Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				continue;
			}
			else if (switcher == SettingsMenu::Width && width < 30) {
				system("cls");
				width++;
				wcout << "Длина поля = " << length << "\n";
				wcout << "<< Ширина поля >> = " << width << "\n";
				wcout << "Здоровье корабля = " << Hero_health << "\n";
				wcout << "Здоровье врагов = " << Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				continue;
			}
			else if (switcher == SettingsMenu::Hero_Health && Hero_health < 5) {
				system("cls");
				Hero_health++;
				wcout << "Длина поля = " << length << "\n";
				wcout << "Ширина поля = " << width << "\n";
				wcout << "<< Здоровье корабля >> = " << Hero_health << "\n";
				wcout << "Здоровье врагов = " << Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				continue;
			}
			else if (switcher == SettingsMenu::Enemy_Health && Enemy_health < 3) {
				system("cls");
				Enemy_health++;
				wcout << "Длина поля = " << length << "\n";
				wcout << "Ширина поля = " << width << "\n";
				wcout << "Здоровье корабля = " << Hero_health << "\n";
				wcout << "<< Здоровье врагов >> = " << Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				continue;
			}
		}

		if (GetKeyState(VK_RETURN) < 0) {
			if (switcher == SettingsMenu::Back) {
				break;
			}
			else if (switcher == SettingsMenu::Defaults) {
				system("cls");
				length = 30;
				width = 15;
				Hero_health = 3;
				Enemy_health = 1;
				wcout << "Длина поля = " << length << "\n";
				wcout << "Ширина поля = " << width << "\n";
				wcout << "Здоровье корабля = " << Hero_health << "\n";
				wcout << "Здоровье врагов = " << Enemy_health << "\n";
				wcout << "<< Установить значения по умолчанию >>\n";
				wcout << "Назад\n";
				Sleep(125);
				continue;
			}
		}
	}
}

void HelpMenu() {
	wcout << "W - перемещение вверх\n";
	wcout << "S - перемещение вниз\n";
	wcout << "Пробел - выстрел\n";
	wcout << "<< Назад >>\n";

	Sleep(250);
	while (true) {
		if (GetKeyState(VK_RETURN) < 0) {
			break;
		}
	}
}

void LeaderBoard(bool &IsOpened) {
	if (!IsOpened) {
		IsOpened = true;
		ReadFromFile(FilePath, scoreboard);
		sort(scoreboard.begin(), scoreboard.end(), [](const Board &a, const Board &b) { return a.score < b.score; });
	}

	int players_count = scoreboard.size();
	if (players_count > 10) {
		players_count = 10;
	}

	for (int i = 0; i < players_count; i++) {
		cout << "Имя пользователя: " << scoreboard[i].name << "\n";
		cout << "Счёт: " << scoreboard[i].score << "\n\n";
	}

	cout << "<< Назад >>\n";

	Sleep(250);
	while (true) {
		if (GetKeyState(VK_RETURN) < 0) {
			break;
		}
	}
}