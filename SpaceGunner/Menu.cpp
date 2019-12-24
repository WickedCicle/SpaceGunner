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

enum EscapeMenu {
	Continue = 0,
	ExitGame = 1
};

void MainMenu(Settings_Args &SetArgs) {
	bool IsLeaderBoardOpened = false;
	int switcher = MainMenu::Play;
	wcout << "<< Играть >>\n";
	wcout << "Настройки\n";
	wcout << "Как играть\n";
	wcout << "Таблица лидеров\n";
	wcout << "Выход\n";

	while (true) {
		if (GetKeyState('W') < 0 || GetKeyState(VK_UP) < 0) {
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
		if (GetKeyState('S') < 0 || GetKeyState(VK_DOWN) < 0) {
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
				cin.ignore(cin.rdbuf()->in_avail());
				system("cls");
				break;
			}
			else if (switcher == MainMenu::Settings) {
				system("cls");
				SettingsMenu(SetArgs);;
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

void SettingsMenu(Settings_Args &SetArgs) {
	int switcher = SettingsMenu::Length;
	wcout << "<< Длина поля >> = " << SetArgs.length << "\n";
	wcout << "Ширина поля = " << SetArgs.width << "\n";
	wcout << "Здоровье корабля = " << SetArgs.Hero_health << "\n";
	wcout << "Здоровье врагов = " << SetArgs.Enemy_health << "\n";
	wcout << "Установить значения по умолчанию" << "\n";
	wcout << "Назад\n";

	while (true) {
		if (GetKeyState('W') < 0 || GetKeyState(VK_UP) < 0) {
			Sleep(250);
			system("cls");
			if (switcher == SettingsMenu::Length) {
				wcout << "Длина поля = " << SetArgs.length << "\n";
				wcout << "Ширина поля = " << SetArgs.width << "\n";
				wcout << "Здоровье корабля = " << SetArgs.Hero_health << "\n";
				wcout << "Здоровье врагов = " << SetArgs.Enemy_health << "\n";
				wcout << "Установить значения по умолчанию" << "\n";
				wcout << "<< Назад >>" << "\n";
				switcher = SettingsMenu::Back;
				continue;
			}
			else if (switcher == SettingsMenu::Width) {
				wcout << "<< Длина поля >> = " << SetArgs.length << "\n";
				wcout << "Ширина поля = " << SetArgs.width << "\n";
				wcout << "Здоровье корабля = " << SetArgs.Hero_health << "\n";
				wcout << "Здоровье врагов = " << SetArgs.Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				switcher = SettingsMenu::Length;
				continue;
			}
			else if (switcher == SettingsMenu::Hero_Health) {
				wcout << "Длина поля = " << SetArgs.length << "\n";
				wcout << "<< Ширина поля >> = " << SetArgs.width << "\n";
				wcout << "Здоровье корабля = " << SetArgs.Hero_health << "\n";
				wcout << "Здоровье врагов = " << SetArgs.Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				switcher = SettingsMenu::Width;
				continue;
			}
			else if (switcher == SettingsMenu::Enemy_Health) {
				wcout << "Длина поля = " << SetArgs.length << "\n";
				wcout << "Ширина поля = " << SetArgs.width << "\n";
				wcout << "<< Здоровье корабля >> = " << SetArgs.Hero_health << "\n";
				wcout << "Здоровье врагов = " << SetArgs.Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				switcher = SettingsMenu::Hero_Health;
				continue;
			}
			else if (switcher == SettingsMenu::Defaults) {
				wcout << "Длина поля = " << SetArgs.length << "\n";
				wcout << "Ширина поля = " << SetArgs.width << "\n";
				wcout << "Здоровье корабля = " << SetArgs.Hero_health << "\n";
				wcout << "<< Здоровье врагов >> = " << SetArgs.Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				switcher = SettingsMenu::Enemy_Health;
				continue;
			}
			else if (switcher == SettingsMenu::Back) {
				wcout << "Длина поля = " << SetArgs.length << "\n";
				wcout << "Ширина поля = " << SetArgs.width << "\n";
				wcout << "Здоровье корабля = " << SetArgs.Hero_health << "\n";
				wcout << "Здоровье врагов = " << SetArgs.Enemy_health << "\n";
				wcout << "<< Установить значения по умолчанию >>\n";
				wcout << "Назад\n";
				switcher = SettingsMenu::Defaults;
				continue;
			}
		}
		if (GetKeyState('S') < 0 || GetKeyState(VK_DOWN) < 0) {
			Sleep(250);
			system("cls");
			if (switcher == SettingsMenu::Length) {
				wcout << "Длина поля = " << SetArgs.length << "\n";
				wcout << "<< Ширина поля >> = " << SetArgs.width << "\n";
				wcout << "Здоровье корабля = " << SetArgs.Hero_health << "\n";
				wcout << "Здоровье врагов = " << SetArgs.Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				switcher = SettingsMenu::Width;
				continue;
			}
			else if (switcher == SettingsMenu::Width) {
				wcout << "Длина поля = " << SetArgs.length << "\n";
				wcout << "Ширина поля = " << SetArgs.width << "\n";
				wcout << "<< Здоровье корабля >> = " << SetArgs.Hero_health << "\n";
				wcout << "Здоровье врагов = " << SetArgs.Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				switcher = SettingsMenu::Hero_Health;
				continue;
			}
			else if (switcher == SettingsMenu::Hero_Health) {
				wcout << "Длина поля = " << SetArgs.length << "\n";
				wcout << "Ширина поля = " << SetArgs.width << "\n";
				wcout << "Здоровье корабля = " << SetArgs.Hero_health << "\n";
				wcout << "<< Здоровье врагов >> = " << SetArgs.Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				switcher = SettingsMenu::Enemy_Health;
				continue;
			}
			else if (switcher == SettingsMenu::Enemy_Health) {
				wcout << "Длина поля = " << SetArgs.length << "\n";
				wcout << "Ширина поля = " << SetArgs.width << "\n";
				wcout << "Здоровье корабля = " << SetArgs.Hero_health << "\n";
				wcout << "Здоровье врагов = " << SetArgs.Enemy_health << "\n";
				wcout << "<< Установить значения по умолчанию >>\n";
				wcout << "Назад\n";
				switcher = SettingsMenu::Defaults;
				continue;
			}
			else if (switcher == SettingsMenu::Defaults) {
				wcout << "Длина поля = " << SetArgs.length << "\n";
				wcout << "Ширина поля = " << SetArgs.width << "\n";
				wcout << "Здоровье корабля = " << SetArgs.Hero_health << "\n";
				wcout << "Здоровье врагов = " << SetArgs.Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "<< Назад >>\n";
				switcher = SettingsMenu::Back;
				continue;
			}
			else if (switcher == SettingsMenu::Back) {
				wcout << "<< Длина поля >> = " << SetArgs.length << "\n";
				wcout << "Ширина поля = " << SetArgs.width << "\n";
				wcout << "Здоровье корабля = " << SetArgs.Hero_health << "\n";
				wcout << "Здоровье врагов = " << SetArgs.Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				switcher = SettingsMenu::Length;
				continue;
			}
		}

		if (GetKeyState(VK_LEFT) < 0 || GetKeyState('A') < 0) {
			Sleep(125);
			if (switcher == SettingsMenu::Length && SetArgs.length > 30) {
				system("cls");
				SetArgs.length--;
				wcout << "<< Длина поля >> = " << SetArgs.length << "\n";
				wcout << "Ширина поля = " << SetArgs.width << "\n";
				wcout << "Здоровье корабля = " << SetArgs.Hero_health << "\n";
				wcout << "Здоровье врагов = " << SetArgs.Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				continue;
			}
			else if (switcher == SettingsMenu::Width && SetArgs.width > 15) {
				system("cls");
				SetArgs.width--;
				wcout << "Длина поля = " << SetArgs.length << "\n";
				wcout << "<< Ширина поля >> = " << SetArgs.width << "\n";
				wcout << "Здоровье корабля = " << SetArgs.Hero_health << "\n";
				wcout << "Здоровье врагов = " << SetArgs.Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				continue;
			}
			else if (switcher == SettingsMenu::Hero_Health && SetArgs.Hero_health > 1) {
				system("cls");
				SetArgs.Hero_health--;
				wcout << "Длина поля = " << SetArgs.length << "\n";
				wcout << "Ширина поля = " << SetArgs.width << "\n";
				wcout << "<< Здоровье корабля >> = " << SetArgs.Hero_health << "\n";
				wcout << "Здоровье врагов = " << SetArgs.Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				continue;
			}
			else if (switcher == SettingsMenu::Enemy_Health && SetArgs.Enemy_health > 1) {
				system("cls");
				SetArgs.Enemy_health--;
				wcout << "Длина поля = " << SetArgs.length << "\n";
				wcout << "Ширина поля = " << SetArgs.width << "\n";
				wcout << "Здоровье корабля = " << SetArgs.Hero_health << "\n";
				wcout << "<< Здоровье врагов >> = " << SetArgs.Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				continue;
			}
		}
		if (GetKeyState(VK_RIGHT) < 0 || GetKeyState('D') < 0) {
			Sleep(125);
			if (switcher == SettingsMenu::Length && SetArgs.length < 70) {
				system("cls");
				SetArgs.length++;
				wcout << "<< Длина поля >> = " << SetArgs.length << "\n";
				wcout << "Ширина поля = " << SetArgs.width << "\n";
				wcout << "Здоровье корабля = " << SetArgs.Hero_health << "\n";
				wcout << "Здоровье врагов = " << SetArgs.Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				continue;
			}
			else if (switcher == SettingsMenu::Width && SetArgs.width < 30) {
				system("cls");
				SetArgs.width++;
				wcout << "Длина поля = " << SetArgs.length << "\n";
				wcout << "<< Ширина поля >> = " << SetArgs.width << "\n";
				wcout << "Здоровье корабля = " << SetArgs.Hero_health << "\n";
				wcout << "Здоровье врагов = " << SetArgs.Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				continue;
			}
			else if (switcher == SettingsMenu::Hero_Health && SetArgs.Hero_health < 5) {
				system("cls");
				SetArgs.Hero_health++;
				wcout << "Длина поля = " << SetArgs.length << "\n";
				wcout << "Ширина поля = " << SetArgs.width << "\n";
				wcout << "<< Здоровье корабля >> = " << SetArgs.Hero_health << "\n";
				wcout << "Здоровье врагов = " << SetArgs.Enemy_health << "\n";
				wcout << "Установить значения по умолчанию\n";
				wcout << "Назад\n";
				continue;
			}
			else if (switcher == SettingsMenu::Enemy_Health && SetArgs.Enemy_health < 3) {
				system("cls");
				SetArgs.Enemy_health++;
				wcout << "Длина поля = " << SetArgs.length << "\n";
				wcout << "Ширина поля = " << SetArgs.width << "\n";
				wcout << "Здоровье корабля = " << SetArgs.Hero_health << "\n";
				wcout << "<< Здоровье врагов >> = " << SetArgs.Enemy_health << "\n";
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
				SetArgs.length = 60;
				SetArgs.width = 25;
				SetArgs.Hero_health = 3;
				SetArgs.Enemy_health = 1;
				wcout << "Длина поля = " << SetArgs.length << "\n";
				wcout << "Ширина поля = " << SetArgs.width << "\n";
				wcout << "Здоровье корабля = " << SetArgs.Hero_health << "\n";
				wcout << "Здоровье врагов = " << SetArgs.Enemy_health << "\n";
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

	if (!players_count) {
		cout << "В таблице лидеров пока нет ни одного результата.\n";
	}

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

void EscMenu() {
	system("cls");
	int switcher = EscapeMenu::Continue;
	wcout << L"<< Продолжить >>\n";
	wcout << L"Выход\n";

	while (true) {
		if (GetKeyState('W') < 0 || GetKeyState(VK_UP) < 0) {
			Sleep(250);
			if (switcher == EscapeMenu::Continue) {
				system("cls");
				wcout << L"Продолжить\n";
				wcout << L"<< Выход >>\n";
				switcher = EscapeMenu::ExitGame;
				continue;
			}
			else if (switcher == EscapeMenu::ExitGame) {
				system("cls");
				wcout << L"<< Продолжить >>\n";
				wcout << L"Выход\n";
				switcher = EscapeMenu::Continue;
				continue;
			}
		}
		if (GetKeyState('S') < 0 || GetKeyState(VK_DOWN) < 0) {
			Sleep(250);
			if (switcher == EscapeMenu::Continue) {
				system("cls");
				wcout << L"Продолжить\n";
				wcout << L"<< Выход >>\n";
				switcher = EscapeMenu::ExitGame;
				continue;
			}
			else if (switcher == EscapeMenu::ExitGame) {
				system("cls");
				wcout << L"<< Продолжить >>\n";
				wcout << L"Выход\n";
				switcher = EscapeMenu::Continue;
				continue;
			}
		}
		if (GetKeyState(VK_RETURN) < 0) {
			if (switcher == EscapeMenu::Continue) {
				break;
			}
			else if (switcher == EscapeMenu::ExitGame) {
				ExitProcess(0);
			}
		}
	}
}