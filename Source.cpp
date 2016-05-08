#include "BoardGame.h"
#include "Connect4Game.h"
#include "TicTacToeGame.h"
#include "AI_tictactoe.h"
#include "Player.h"
#include "Input.h"
#include <sstream>
using namespace std;

list<Player>* getPlayers(int number_player) {
	string name;
	char symbol;
	list<Player>* players = new list<Player>();
	string input;
	for (int i = 0; i<number_player; i++)
	{
		cout << "The " << (players->size() == 0 ? "first" : "next") << " player should now enter their name:" << endl;
		//getting player name
		getline(cin, name);
		cout << "Hello " << name << "!" << endl;
		cout << "What would you like your symbol to be? " << endl;
	GETSYMBOL:
		//getting player symbol
		symbol = getChar();
		//Check if the symbol already taken by another player
		if (find_if(players->begin(), players->end(), [symbol](Player p) {return symbol == p.getSymbol(); }) != players->end()) {
			cout << "Symbol already taken, enter another symbol" << endl;
			goto GETSYMBOL;
		}
		//add player to player list
		players->push_back(Player(name, symbol));
		cout << endl;
	}
	return players;
}

void main() {
	BoardGame *b;
	int gameNo, number_players, board_width, board_height, markers_number = 4;
	list<Player> players;
	string Name;
	char Symbol, solo_multi;
	//Welcome to be modified
	cout << "Hello and welcome to board games" << endl << endl << endl;

	while (true)
	{
	TRYAGAIN:
		cout << "Enter 0 To exit the game" << endl;
		cout << "Enter 1 to play Tic Tac Toe" << endl;
		cout << "Enter 2 to play Connect 4 " << endl;
		gameNo = getInt();
		if (gameNo == 0)
			break;
		if (gameNo != 1 && gameNo != 2)
		{
			cout << "Wrong Game Number!!" << endl;
			goto TRYAGAIN;
		}
		cout << endl;

		//solo or Multi
		if (gameNo == 1)
		{
			cout << "Enter 'S' to play solo 'M' to play multiplayer: ";
SOLO_MULTI:
			solo_multi = getChar();
			if (solo_multi == 'S' || solo_multi == 's')
			{
				AI_tictactoe game;
				game.playgame();
				cout << endl << endl << endl;
				goto TRYAGAIN;
			}
			else if (!(solo_multi == 'M' || solo_multi == 'm')) {
				cout << "Please, enter only 'M' or 'S' " << endl;
				goto SOLO_MULTI;
			}
		}

		//Getting the board dimensions
		cout << endl;
		int min_dimension = (gameNo == 2 ? 4 : 3);
		int max_dimension = 15;
		cout << "How wide would you like the board to be? (Enter a number between " << min_dimension << " and " << max_dimension << ")" << endl;
	BOARD_WIDTH:
		board_width = getInt();
		if (board_width < min_dimension || board_width > max_dimension)
		{
			cout << "Invalid width, Enter a number between " << min_dimension << " and " << max_dimension << endl;
			goto BOARD_WIDTH;
		}
		cout << "How high would you like the board to be? (Enter a number between " << min_dimension << " and " << max_dimension << ")" << endl;
	BOARD_HEIGHT:
		board_height = getInt();
		if (board_height < min_dimension || board_height > max_dimension)
		{
			cout << "Invalid height, Enter a number between " << min_dimension << " and " << max_dimension << endl;
			goto BOARD_HEIGHT;
		}

		//Getting the number of consecutive markers needed to win in case of tic tac toe
		cout << endl;
		if (gameNo == 1)
		{
			cout << "How many markers horizontal, vertical or diagonal should be needed to win? (Enter a number between 3 and "
				<< min(board_width, board_height) << ")" << endl;
		MarkerInput:
			markers_number = getInt();
			if (markers_number < 3 || markers_number > min(board_width, board_height))
			{
				cout << "Invalid number, please enter a number between 3 and " << min(board_width, board_height) << ")" << endl;
				goto MarkerInput;
			}
		}

		//playerdata
	PlayerData:
		int max_players = ((board_width * board_height) / markers_number);
		cout << "Enter number of players: (Enter a number between 2 and " << max_players << ")" << endl;;
		number_players = getInt();
		if (number_players > max_players|| number_players < 2)
		{
			cout << "Board Can't take this amount of players!" << endl;
			goto PlayerData;
		}
		players = *getPlayers(number_players);

		//initalizing the game
		if (gameNo == 1)
			b = new TicTacToeGame(board_width, board_height, markers_number, players);

		if (gameNo == 2)
			b = new Connect4Game(board_width, board_height, players);
		//srtat
		b->startGame();
		cout << endl << endl << endl;
	}
}