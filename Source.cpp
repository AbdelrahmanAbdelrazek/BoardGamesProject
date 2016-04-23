#include "BoardGame.h"
#include "Connect4Game.h"
#include "TicTacToeGame.h"
#include "Player.h"
using namespace std;

void main() {
	Player p0 = Player("Abdoo", 'Y');
	Player p1 = Player("TikTak", '#');
	Player player_arr[2] = { p0, p1 };
	
	BoardGame *b = new Connect4Game(5, 5,list<Player>(player_arr, player_arr+2));
	b->startGame();
	system("pause");
}