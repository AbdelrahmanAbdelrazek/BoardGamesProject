#include "Connect4Game.h"
#include "Input.h"

bool Connect4Game::playTurn(Player p)
{
	//Take input from Player p
	cout << p.getName() << " Turn!" << endl;
TRYAGAIN:
	cout << "Enter the column number where you wish to place your marker: ";
	int column;
	column = getInt();
	column--;
	//check if player input is valid(within the board and the column is not full)
	if (column >= _board_width || column < 0) {
		cout << "Invalid Column number, try again!" << endl;
		goto TRYAGAIN;
	}
	else if (board[column].back() != ' ') {
		cout << "Column is full, try again!" << endl;
		goto TRYAGAIN;
	}
	//Put Symbol in the right place in board
	int row = _columns_counters[column]++;
	board[column][row] = p.getSymbol();
	UndoParameters ToPush;
	ToPush.SetPlayer(p);
	ToPush.SetX(column);
	ToPush.SetY(row);
	UndoStack.push(ToPush);
	return hasWonDiagonalyRight(column, row) || hasWonDiagonalyLeft(column, row) ||
		hasWonVertically(column, row) || hasWonHorizontally(column, row);
}
Player Connect4Game::Undo()
{
	board[UndoStack.top().GetX()][UndoStack.top().GetY()] = ' ';
	_columns_counters[UndoStack.top().GetX()]--;
	Player temp = UndoStack.top().GetPlayer();
	UndoStack.pop();
	return temp;
}