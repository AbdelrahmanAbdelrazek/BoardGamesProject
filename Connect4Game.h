#pragma once
#include "BoardGame.h"
class Connect4Game : public BoardGame
{
private:
	bool virtual playTurn(Player p);
	Player virtual Undo();
	vector<int> _columns_counters;
public:
	Connect4Game(int width, int height, list<Player> players)
		:BoardGame(width, height, 4, players) {
		_columns_counters = vector<int>(width);
	}
};

