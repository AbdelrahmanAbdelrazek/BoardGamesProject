#include "BoardGame.h"
#include "Sorting Functions.h"
#include "Input.h"

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
		}
		else
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
		if (i < 0 || j <0 || board[x][y] != board[i][j] || board[i][j] == ' ') {
			return false;
		}
	}

	return true;
}

bool BoardGame::hasWonVertically(int x, int y)
{
	//function input checks
	assert(x >= 0 && x < _board_width);
	assert(y >= 0 && y < _board_height);
	//input is considered as top , iterating to bottom ( consecutive markers to win ) times  checking if symbol is not equal or end of board is reached
	//if any of the 2 conditions is true then return false 
	//if you get out of the loop return true 
	int CurrentHeight = y;
	int counter = 0;
	for (counter = 0; counter < _no_consecutive_markers_to_win - 1; counter++)
	{
		if (CurrentHeight == 0)
		{
			return false;
		}
		if (board[x][CurrentHeight] != board[x][CurrentHeight - 1] || CurrentHeight >= _board_height)
		{
			return false;
		}
		CurrentHeight--;
	}
	return true;
}

bool BoardGame::hasWonHorizontally(int x, int y)
{

	//function input checks
	assert(x >= 0 && x < _board_width);
	assert(y >= 0 && y < _board_height);
	int CurrentWidth = x;
	int counter = 0;
	//move right to check first
	for (counter = 0; counter < _no_consecutive_markers_to_win - 1; counter++)
	{
		if (CurrentWidth == _board_width - 1)
			goto MoveLeftAndCheck;
		if (board[CurrentWidth][y] != board[CurrentWidth + 1][y] || board[CurrentWidth][y] == ' ')
		{
			goto MoveLeftAndCheck;
		}
		CurrentWidth++;
	}
	return true;
MoveLeftAndCheck:
	for (counter = 0; counter < _no_consecutive_markers_to_win - 1; counter++)
	{
		if (CurrentWidth == 0)
		{
			return false;
		}
		if (board[CurrentWidth][y] != board[CurrentWidth - 1][y] || CurrentWidth <= 0 || board[CurrentWidth][y] == ' ')
		{
			return false;
		}
		CurrentWidth--;
	}
	return true;

}


void BoardGame::printBoard()
{
	const int SPACING = 4;
	int x = board.size() > 9;

	cout << endl << endl;
	for (int row = _board_height - 1; row >= 0; row--) {
		cout << string(SPACING, ' ');
		//print line
		cout << string((_board_width * 4 + 3), '-') << endl;
		//print row
		cout << string(SPACING, ' ');
		cout << (row < 9 ? " " : "") << row + 1 << '|';
		for (int column = 0; column < _board_width; column++) {
			cout << " " << board[column][row] << " |";
		}
		cout << endl;
	}

	//print column numbers
	cout << string(SPACING, ' ');
	cout << string((_board_width * 4 + 3), '-') << endl;
	cout << string(SPACING, ' ');
	cout << "  |";
	for (int i = 0; i < _board_width; i++)
		cout << " " << i + 1 << (i < 9 ? " " : "") << "|";
	cout << endl << endl;
}

void BoardGame::startGame()
{
	list<Player>::iterator it = _players.begin(); //players iterator
	int turns_counter = 0;
	printBoard();
	while (true) {
		//giving option to undo
		if (!UndoStack.empty())
		{
			cout << "Press U to Undo anything else to continue :" << endl;
			char choice;
			choice = getChar();
			if (choice == 'u' || choice == 'U')
			{
				Player GivingTurn = Undo();
				printBoard();
				it--; //turn goes to the previous player
				turns_counter--;
			}
		}
		//checks if number of plays is equal to number of places in the board
		if (turns_counter >= _board_width *_board_height) {
			cout << "Game ended in tie" << endl;
			break;
		}
		//if the iterator reaches to the end of the players list .. the iterator start over from the begining
		if (it == _players.end())
			it = _players.begin();
		//PlayTurn will write the player turn in the board and return true if the player who played the turn has won
		if (playTurn(*it)) {
			printBoard();
			cout << (*it).getName() << " Won!" << endl;
			SetHighScore(*it, turns_counter);
			break;
		}
		printBoard();
		turns_counter++;
		it++;
	}
}
void BoardGame::SetHighScore(Player Winner, int TurnsToWin)
{
	HighScore a;
	a.SetScore(TurnsToWin);
	a.SetPlayer(Winner.getName());
	HighScoresList.push_back(a);
	HighScoresList.sort(SortHighScores);
	SaveHighScoresToFile();
}
void BoardGame::LoadHighScoreFromFile()
{
	string line;
	fstream HighScoreFile("HighScores.txt", fstream::in | fstream::out | fstream::app);
	HighScore ToPush;
	while (getline(HighScoreFile, line))
	{
		ToPush.SetPlayer(line.substr(0, line.find(' ')));
		line.erase(0, line.find(' ') + 1);
		ToPush.SetScore(stoi(line));
		HighScoresList.push_back(ToPush);
	}
}
void BoardGame::SaveHighScoresToFile()
{
	fstream HighScoreFile("HighScores.txt", fstream::in | fstream::out | fstream::trunc);
	for (list<HighScore>::iterator i = HighScoresList.begin(); i != HighScoresList.end(); ++i)
	{
		HighScoreFile << i->GetPlayer() << " " << i->GetScore() << endl;
	}
}
void BoardGame::PrintHighScores()
{
	fstream HighScoreFile("HighScores.txt", fstream::in | fstream::out | fstream::app);
}

