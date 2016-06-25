# BoardGamesProject

##1.0 Project Description
Implementation of “connect four” and “Tic tac toe” board games where there’s a board which has empty places/squares and players take turns in filling these empty places according to some rules. Program decides which player won the game according to the game rules.
	###Connect Four:
The Connect 4 Board Game rules are very easy to understand. To win Connect Four, all you have to do is connect four of your pieces in a row. This can be done horizontally, vertically or diagonally. Each player will drop in one piece at a time.
The game is over either when one of the players reaches four in a row, or when all slots are filled, ending in a stalemate.
	###Tic Tac Toe:
Also known as Xs and Os is a game for two players, who take turns marking the spaces in a grid. The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row wins the game.
Tic tac toe is similar to connect 4 but the player can insert the X or O in any place in the grid while in connect 4 the player can only choose a column to put his piece in.

##2.0 Features and limitations
	The board width and height can range from 3 to 15 in case of Tic Tac Toe and 4 to 15 in case of Connect 4.
	User can play Tic Tac Toe against the computer in a 3x3 board.
	Players can specify the number of markers needed to win in case of Tic Tac Toe game.
	Game supports more than 2 players. Maximum number of players depends on the board size and number of consecutive markers needed to win.
 Max Players=  (BoardWidth * BoardHeight)/noMarkersNeededToWin  
	Player can undo previous steps.
	User can save and load games to/from disk.
	The game keeps track of high scores.
