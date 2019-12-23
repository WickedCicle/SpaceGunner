#include "ScoreBoard.h";

void ReadFromFile(string FilePath, vector<Board> &scoreboard) {
	ifstream File;
	Board board;
	string str;
	string name;
	int score;
	bool is_name = 1;

	try {
		if (File.is_open()) {
			throw "������. ���� ��� ������.";
		}
		File.open(FilePath);
		if (!File.is_open()) {
			throw "������ �������� �����.";
		}
	}
	catch (wstring str) {
		wcout << str;
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

void AddToFile(string name, int score, string FilePath) {
	ofstream File;
	try {
		if (File.is_open()) {
			throw "������. ���� ��� ������.";
		}
		File.open(FilePath, ofstream::app);
		if (!File.is_open()) {
			throw "������ �������� �����.";
		}
	}
	catch (wstring str) {
		wcout << str;
	}

	File << name << endl;
	File << score << endl;

	File.close();
}

string WriteName() {
	string name;
	wcout << "������� ���� ���.\n";
	cin.get();
	do {
		getline(cin, name);
	} while (!CheckName(name));

	system("cls");

	return name;
}

bool CheckName(string name) {
	if (name[0] == '\0') {
		wcout << "������. ������� ������ ������.\n";
		return false;
	}
	if (name[0] == ' ') {
		wcout << "��� �� ����� ���������� � �������.\n";
		return false;
	}
	if (name[name.length() - 1] == ' ') {
		wcout << "��� �� ����� ������������� ��������.\n";
		return false;
	}
	for (int i = 0; i < name.length(); i++) {
		if (name[i] == ' ') {
			wcout << "������. ������������� �������.\n";
			continue;
		}
		if (!isdigit(name[i]) && !isalpha(name[i])) {
			wcout << "������. ������������ ����������� �������.\n";
			return false;
		}
	}

	return true;
}