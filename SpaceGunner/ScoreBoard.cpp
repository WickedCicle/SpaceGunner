#include "ScoreBoard.h";

using namespace std;

// считывание информации из файла
void ReadFromFile(string FilePath, vector<Board> &scoreboard) {
	ifstream File;
	Board board; // структура для хранения имени и счёта
	string str; // временная строка
	string name; // переменная для хранения имени
	int score; // переменная для хранения счёта
	bool is_name = 1;

	try {
		if (File.is_open()) {
			throw string("Ошибка. Файл уже открыт.\n");
		}
		File.open(FilePath);
		if (!File) {
			ofstream file(FilePath);
		}
	}
	catch (string &str) {
		cout << str;
	}

	while (getline(File, str)) {
		if (is_name) {
			name = str;
			board.name = name;
		}
		else {
			score = atoi(str.c_str());
			board.score = score;
			scoreboard.push_back(board);
		}
		is_name = !is_name;
	}

	File.close();
}

// добавление информации о пользователе в файл
void AddToFile(string name, int score, string FilePath) {
	ofstream File;
	try {
		if (File.is_open()) {
			throw string("Ошибка. Файл уже открыт.");
		}
		File.open(FilePath, ofstream::app);
		if (!File.is_open()) {
			ofstream file(FilePath);
		}
	}
	catch (wstring str) {
		wcout << str;
	}

	// добавление имени и счёта в файл
	File << name << endl;
	File << score << endl;

	File.close();
}

// ввод имени пользователя
string WriteName() {
	string name;
	wcout << "Введите ваше имя.\n";
	do {
		getline(cin, name);
	} while (!CheckName(name));

	system("cls");

	return name;
}

// проверка правильности ввода имени
bool CheckName(string name) {
	if (name[0] == '\0') {
		wcout << "Ошибка. Введена пустая строка.\n";
		return false;
	}
	if (name[0] == ' ') {
		wcout << "Имя не может начинаться с пробела.\n";
		return false;
	}
	if (name[name.length() - 1] == ' ') {
		wcout << "Имя не может заканчиваться пробелом.\n";
		return false;
	}
	for (int i = 0; i < name.length(); i++) {
		if (name[i] == ' ') {
			wcout << "Ошибка. Использование пробела.\n";
			continue;
		}
		if (!isdigit(name[i]) && !isalpha(name[i])) {
			wcout << "Ошибка. Допускается использование латиницы и цифр.\n";
			return false;
		}
	}

	return true;
}