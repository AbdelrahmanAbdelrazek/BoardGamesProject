#include "AI_tictactoe.h"


AI_tictactoe::AI_tictactoe()
{
	board.resize(3, vector<char>(3));
	empty = ' ';
}
void AI_tictactoe::playgame() {
	bool playagain = true;
	bool isValid;
	char again, input, current_player, start;
	clearboard();
	string player_1, player_2;
	int x, y;
	// choosing symbol
	cout << "please choose your symbol (X or O) :";

	do {
		input = getChar();
		if (input == 'x' || input == 'X') {
			aiPlayer = 'O';
			humanPlayer = 'X';
			break;
		}
		else if (input == 'o' || input == 'O') {
			aiPlayer = 'X';
			humanPlayer = 'O';
			break;
		}
		else {
			cout << "Please enter X or O!" << endl;
		}
	} while (true);

	//choosing which one to start
	cout << "choose which one start: H for 'human' or C for 'computer' ";
	// validation for input
	do {
		start = getChar();
		if (start == 'h' || start == 'H') {
			current_player = humanPlayer;
			break;
		}
		else if (start == 'c' || start == 'C') {
			current_player = aiPlayer;
			break;
		}
		else {
			cout << "Please enter C or H!" << endl;
		}
	} while (true);

	// game loop
	bool isDone = false;
	while (isDone == false)
	{
		printboard();

		//human player move
		if (current_player == humanPlayer) {

			do {
				cout << "Enter the X-Coordinate of where you wish to place your marker: " << endl;
				y = getInt();
				cout << "Enter the Y-Coordinate of where you wish to place your marker: " << endl;
				x = getInt();
			} while (check_Coord(x, y));

			if (placemarker(x - 1, y - 1, current_player)) {
				current_player = changePlayers(current_player);
			}
		}
		else {
			cout << "It's computer  turn : " << endl;
			AIperformMove();
			current_player = changePlayers(current_player);
		}
		if (checkforVectory() == humanPlayer) {
			printboard();

			cout << "Game is Over YOU unexpectedly has Won !!" << endl;
			isDone = true;
		}
		else if (checkforVectory() == aiPlayer) {
			printboard();
			cout << "Game is Over  YOU LOSE " << endl;
			isDone = true;
		}
		else if (checkforVectory() == 't') {
			printboard();
			cout << "Game is Over" << " No one Won !!" << endl;
			isDone = true;
		}
	}
}

void AI_tictactoe::clearboard() {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			board[i][j] = ' ';
		}
	}

}
void AI_tictactoe::printboard() {
	cout << "-------------" << endl;

	for (int i = 0; i < board.size(); i++) {
		cout << "  " << i + 1 << " ";
	}
	cout << endl;
	for (int i = 0; i < board.size(); i++) {
		cout << i + 1 << " ";
		for (int j = 0; j < board[i].size(); j++) {
			cout << board[i][j] << " | ";
		}
		cout << endl;
	}

	cout << "-------------" << endl;

}

bool AI_tictactoe::check_Coord(int x, int y) {

	if (x<1 || x>board.size() || y<1 || y>board.size()) {
		cout << "Invalid Coordinates !!" << endl;
		return true;
	}
	else {
		return false;
	}
}

bool AI_tictactoe::placemarker(int x, int y, char x_o) {
	if (board[x][y] != ' ' && x_o != empty) {
		cout << "This place in not empty!!  choose another place" << endl;
		return false;
	}
	else {
		board[x][y] = x_o;
		return true;
	}
}

char AI_tictactoe::changePlayers(char current) {

	if (current == 'X') {
		return 'O';
	}
	else {
		return 'X';
	}

}

char AI_tictactoe::checkforVectory() {

	//check for rows and columns
	for (int i = 0; i < board.size(); i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')return board[i][1];
		else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')return board[1][i];
	}
	//check for two diagonals
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')return board[1][1];
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')return board[1][1];

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[i][j] == empty) return empty;
		}
	}
	return 't';
}
// AI choosing for best move
AI_tictactoe::AIMove AI_tictactoe::AIgetBestMove(char current) {

	char rv = checkforVectory();
	if (rv == aiPlayer) {
		return AIMove(10);
	}
	else if (rv == humanPlayer) {
		return AIMove(-10);
	}
	else if (rv == 't') {
		return AIMove(0);
	}
	bool done = false;
	vector<AIMove> moves;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[i][j] == empty) {
				AIMove move;
				move.x = i;
				move.y = j;
				placemarker(i, j, current);

				if (current == aiPlayer) {
					move.score = AIgetBestMove(humanPlayer).score;
				}
				else {
					move.score = AIgetBestMove(aiPlayer).score;
				}
				moves.push_back(move);
				placemarker(i, j, empty);
			}
		}
	}


	int bestmove_index = 0;
	if (current == aiPlayer) {
		int bestscore = -1000;
		for (int i = 0; i < moves.size(); i++) {
			if (moves[i].score >= bestscore) {
				bestmove_index = i;
				bestscore = moves[i].score;
			}
		}
	}
	else {
		int bestscore = 1000;
		for (int i = 0; i < moves.size(); i++) {
			if (moves[i].score <= bestscore) {
				bestmove_index = i;
				bestscore = moves[i].score;
			}
		}
	}
	return moves[bestmove_index];
};
void AI_tictactoe::AIperformMove() {
	AIMove bestmove = AIgetBestMove(aiPlayer);
	placemarker(bestmove.x, bestmove.y, aiPlayer);
};