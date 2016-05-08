#pragma once
#include "Player.h"
class UndoParameters {
private:
	Player PlayerTurn;
	int X_Coordinate;
	int Y_Coordinate;
public:
	void SetPlayer(Player p)
	{
		PlayerTurn = p;
	}
	void SetX(int x)
	{
		X_Coordinate = x;
	}
	void SetY(int y)
	{
		Y_Coordinate = y;
	}
	Player GetPlayer()
	{
		return PlayerTurn;
	}
	int GetX()
	{
		return X_Coordinate;
	}
	int GetY()
	{
		return Y_Coordinate;
	}

};
