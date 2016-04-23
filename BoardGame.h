#pragma once
#include<iostream>
#include<vector>
#include <list>
#include <string>
#include<assert.h>
#include <algorithm>  
#include "Player.h"
using namespace std;

class BoardGame
{
protected:
	vector<vector<char>> board;
	list<Player> _players;
	int _board_width;
	int _board_height;
	int _no_consecutive_markers_to_win; //number of consecutive markers (horizontal, vertical or diagonal) needed to win
	bool virtual playTurn(Player player) = 0;
	bool hasWonDiagonalyLeft(int x, int y);
	bool hasWonDiagonalyRight(int x, int y);
	bool hasWonVertically(int x, int y);
	bool hasWonHorizontally(int x, int y);
public:
	BoardGame(int width, int height, int no_consecutive_markers_to_win, list<Player> players);
	void printBoard();
	void startGame();
};

