<h1>BoardGamesProject</h1>

<h2>1.0 Project Description</h2>
Implementation of “connect four” and “Tic tac toe” board games where there’s a board which has empty places/squares and players take turns in filling these empty places according to some rules. Program decides which player won the game according to the game rules.
<ul>
	<li><strong>Connect Four</strong>:
	The Connect 4 Board Game rules are very easy to understand. To win Connect Four, all you have to do is connect four of your pieces in a row. This can be done horizontally, vertically or diagonally. Each player will drop in one piece at a time.
	The game is over either when one of the players reaches four in a row, or when all slots are filled, ending in a stalemate.
	</li>
	<li><strong>Tic Tac Toe:</strong>
	Also known as Xs and Os is a game for two players, who take turns marking the spaces in a grid. The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row wins the game.
	</li>
</ul>
Tic tac toe is similar to connect 4 but the player can insert the X or O in any place in the grid while in connect 4 the player can only choose a column to put his piece in.


<h2>2.0 Features and limitations</h2>
<ol>
<li>The board width and height can range from 3 to 15 in case of Tic Tac Toe and 4 to 15 in case of Connect 4.</li>
<li>User can play Tic Tac Toe against the computer in a 3x3 board.</li>
<li>Players can specify the number of markers needed to win in case of Tic Tac Toe game.</li>
<li>Game supports more than 2 players. Maximum number of players depends on the board size and number of consecutive markers needed to win. [ Max Players=  (BoardWidth * BoardHeight)/noMarkersNeededToWin ]  </li>
<li>Player can undo previous steps.</li>
<li>User can save and load games to/from disk.</li>
<li>The game keeps track of high scores.</li>
</ol>

