#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

#ifndef SCORE_H
#define SCORE_H

struct Board {
	bool operator() (int i, int j) {
		return (i < j);
	}
	string name;
	int score;
};

static vector<Board> scoreboard;
static string FilePath = "Scoreboard.txt";

void ReadFromFile(string FilePath, vector<Board> &scoreboard);
void AddToFile(string name, int score, string FilePath);
string WriteName();
bool CheckName(string name);

#endif