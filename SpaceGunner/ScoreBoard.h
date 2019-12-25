#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#ifndef SCORE_H
#define SCORE_H

// структура для хранения имени и счёта игрока
struct Board {
	bool operator() (int i, int j) {
		return (i < j);
	}
	string name;
	int score;
};

static vector<Board> scoreboard; // вектор - хранит, имя пользователя и счёт
static string FilePath = "Scoreboard.txt"; // путь до файла с результатами игроков

void ReadFromFile(string FilePath, vector<Board> &scoreboard); // считывает данные из файла
void AddToFile(string name, int score, string FilePath); // добавляет результат игры в файл
string WriteName(); // ввод имени пользователя
bool CheckName(string name); // проверка корректности ввода имени пользователя

#endif