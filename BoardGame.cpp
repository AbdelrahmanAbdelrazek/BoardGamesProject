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
	board = vector<vector<char>>(board_width, vector<char>(board_height, ' '));
}


bool BoardGame::hasWonDiagonaly(int x, int y)
{
	return false;
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
	for (int row = 0; row < _board_height; row++) {
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
	while (true) {
		if (it == _players.end())
			it = _players.begin();
		if(playTurn(*it)){
			cout << (*it).getName() << " Won!" << endl;
			break;
		}
		
		if (turns_counter > _board_width *_board_height) {
			cout << "Game ended in tie" << endl;
			break;
		}
		
		printBoard();
		turns_counter++;
		it++;
	}
}

