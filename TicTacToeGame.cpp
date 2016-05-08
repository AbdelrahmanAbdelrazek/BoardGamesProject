#include "TicTacToeGame.h"
#include "Input.h"

bool TicTacToeGame::playTurn(Player p)
{
	int Xposition, Yposition;
	//Take input from Player p and make sure it's within the board.
	cout << p.getName() << " Turn!" << endl;
TRYAGAIN:
	//X-Coordinate
	cout << "Enter the X-Coordinate of where you wish to place your marker: ";
	Xposition = getInt();
	Xposition -= 1;
	if (Xposition + 1 > _board_height || Xposition < 0)
	{
		cout << "Invalid X-Coordinate, try again! " << endl;
		goto TRYAGAIN;
	}
	//Y-Coordinate
	cout << "Enter the Y-Coordinate of where you wish to place your marker: ";
	Yposition = getInt();
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
	UndoParameters ToPush;
	ToPush.SetPlayer(p);
	ToPush.SetX(Xposition);
	ToPush.SetY(Yposition);
	UndoStack.push(ToPush);

	//return hasWonDiagonaly(x,y) || hasWonVertically(x,y) || hasWonHorizontally(x,y)
	return (hasWonDiagonalyRight(Xposition, Yposition) || hasWonDiagonalyLeft(Xposition, Yposition) ||
		hasWonVertically(Xposition, Yposition) || hasWonHorizontally(Xposition, Yposition));
}
Player TicTacToeGame::Undo()
{
	board[UndoStack.top().GetX()][UndoStack.top().GetY()] = ' ';
	Player temp = UndoStack.top().GetPlayer();
	UndoStack.pop();
	return temp;
}
