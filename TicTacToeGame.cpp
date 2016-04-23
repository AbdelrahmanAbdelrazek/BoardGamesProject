#include "TicTacToeGame.h"


bool TicTacToeGame::playTurn(Player p)
{
	int Xposition, Yposition;
	//Take input from Player p and make sure it's within the board.
	cout << p.getName() << " Turn!" << endl;
TRYAGAIN:
	//X-Coordinate
	cout <<"Enter the X-Coordinate of where you wish to place your marker: ";
	cin >> Xposition;
	Xposition -= 1;
	if (Xposition + 1 > _board_height || Xposition < 0)
	{
		cout << "Invalid X-Coordinate, try again! " << endl;
		goto TRYAGAIN;
	}
	//Y-Coordinate
	cout << "Enter the Y-Coordinate of where you wish to place your marker: ";
	cin >> Yposition;
	Yposition -= 1;
	if (Yposition + 1 > _board_width || Yposition < 0) {
		cout << "Invalid Y-Coordinate, try again! " << endl;
		goto TRYAGAIN;
	}
	//Make sure the coordiantes point to an empty cell.
	if (board[Xposition][Yposition] != ' ')
	{
		cout << "This place is already occupied, try again!" << endl;
		goto TRYAGAIN;
	}

	//Put Symbol in the right place in board
	board[Xposition][Yposition] = p.getSymbol();

	//return hasWonDiagonaly(x,y) || hasWonVertically(x,y) || hasWonHorizontally(x,y)
	return (hasWonDiagonalyRight(Xposition, Yposition) || hasWonDiagonalyLeft(Xposition, Yposition) ||
		hasWonVertically(Xposition, Yposition) || hasWonHorizontally(Xposition, Yposition));
}
