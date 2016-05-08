#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "input.h"


using namespace std;

class AI_tictactoe
{
private:
	vector<vector<char>> board;
	char aiPlayer, humanPlayer;
	struct AIMove {
		AIMove() {};
		AIMove(int s) : score(s) {}
		int x;
		int y;
		int score;
	};

	char empty;

public:
	AI_tictactoe();
	void clearboard();
	void printboard();
	void playgame();
	bool check_Coord(int x, int y);
	bool placemarker(int x, int y, char x_o);
	char changePlayers(char player);
	char checkforVectory();
	AIMove AIgetBestMove(char current);
	void AIperformMove();
};

