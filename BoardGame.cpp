#include "BoardGame.h"


BoardGame::BoardGame(int board_width, int board_height, int no_consecutive_markers_to_win, list<Player> players)
{
	assert(board_width >= 3 && board_height >= 3);
	assert(no_consecutive_markers_to_win >= 3 && no_consecutive_markers_to_win <= min(board_width, board_height));
	assert(players.size() >= 2);

	_board_height = board_height;
	_board_width = board_width;
	_no_consecutive_markers_to_win = no_consecutive_markers_to_win;
	_players = players;
	board = vector<vector<char>>(board_width, vector<char>(_board_height, ' '));
}


bool BoardGame::hasWonDiagonalyLeft(int x, int y)
{
	assert(x >= 0 && x < _board_width);
	assert(y >= 0 && y < _board_height);
	bool has_won = true;
	int count = 0;
	int j = y + 1;
	for (int i = x - 1; i > x - _no_consecutive_markers_to_win; i--, j++) {
		if (i < 0 || j >= _board_height || board[x][y] != board[i][j] || board[i][j] == ' ') {
			has_won = false;
			break;
		}else
			count++;
	}
	
	if (has_won)
		return true;

	j = y - 1;
	for (int i = x + 1; i < x + _no_consecutive_markers_to_win - count; i++, j--) {
		if (i >= _board_width || j < 0 || board[x][y] != board[i][j] || board[i][j] == ' ') 
			return false;

	}

	return true;
}

bool BoardGame::hasWonDiagonalyRight(int x, int y)
{
	assert(x >= 0 && x < _board_width);
	assert(y >= 0 && y < _board_height);
	bool has_won = true;
	int count = 0;
	int j = y + 1;
	for (int i = x + 1; i < x + _no_consecutive_markers_to_win; i++, j++) {
		if (i >= _board_width || j >= _board_height || board[x][y] != board[i][j] || board[i][j] == ' ') {
			has_won = false;
			break;
		}
		else {
			count++;
		}
	}
	if (has_won)
		return true;
	j = y - 1;
	for (int i = x - 1; i > x - (_no_consecutive_markers_to_win - count); i--, j--) {
		if (i < 0 || j <0 || board[x][y] != board[i][j] || board[i][j] == ' ' ) {
			return false;
		}
	}

	return true;
}

bool BoardGame::hasWonVertically(int x, int y)
{
	return false;
}

bool BoardGame::hasWonHorizontally(int x, int y)
{
	return false;
}


void BoardGame::printBoard()
{
	for (int row = _board_height-1; row >= 0; row--) {
		//print line
		cout << string(_board_width * 4 + 2, '-') << endl;
		//print row
		cout << row + 1 << '|';
		for (int column = 0; column < _board_width; column++) {
			cout << ' ' << board[column][row] << " |";
		}
		cout << endl;
	}
	
	//print column numbers
	cout << string(_board_width * 4 + 2, '-') << endl;
	cout << " |";
	for (int i = 0; i < _board_width; i++)
		cout << " " << i+1 << " |";
	cout << endl;
}

void BoardGame::startGame()
{
	list<Player>::iterator it = _players.begin();
	int turns_counter = 0;
	printBoard();
	while (true) {
		if (it == _players.end())
			it = _players.begin();
		if(playTurn(*it)){
			printBoard();
			cout << (*it).getName() << " Won!" << endl;
			break;
		}
		
		if (turns_counter > _board_width *_board_height) {
			//TODO: prompts the user twice before ending the game
			cout << "Game ended in tie" << endl;
			break;
		}
		
		printBoard();
		turns_counter++;
		it++;
	}
}

