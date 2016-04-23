#include "Connect4Game.h"


bool Connect4Game::playTurn(Player p)
{
	//Take input from Player p
	cout << p.getName() << " Turn!" << endl;
TRYAGAIN:
	cout << "Enter the column number where you wish to place your marker: ";
	int column;
	cin >> column;
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

	return hasWonDiagonalyRight(column, row) || hasWonDiagonalyLeft(column, row) ||
		hasWonVertically(column, row) || hasWonHorizontally(column, row);
}
