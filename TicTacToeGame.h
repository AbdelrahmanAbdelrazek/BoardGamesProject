#pragma once
#include "BoardGame.h"
class TicTacToeGame : public BoardGame
{
private:
	bool virtual playTurn(Player p);
public:
	TicTacToeGame(int width, int height, int no_consecutive_markers_to_win, list<Player> players)
		:BoardGame(width, height, no_consecutive_markers_to_win, players) {}
};

