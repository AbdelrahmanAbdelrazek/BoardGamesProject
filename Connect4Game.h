#pragma once
#include "BoardGame.h"
class Connect4Game : public BoardGame
{
private:
	bool virtual playTurn(Player p);
public:
	Connect4Game(int width, int height, list<Player> players)
		:BoardGame(width, height, 4, players) {}
};

