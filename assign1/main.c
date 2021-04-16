#include <stdio.h>
#include <stdlib.h>

// Check if someone has won the game or if no one wins (Cat's game)
// Returns 0 for no win, player # if a player won, or 3 if there is cat's game.
int check_win(int player, char board[3][3]) {
	int i,j; // i = row, j = col
	char symbol; // X or O depending on who the player is

	// Determine the appropriate symbol for the given player
	if (player == 1)
		symbol = 'X';
	else if (player == 2)
		symbol = 'O';

	// Check row win
	for (i = 0; i < 3; i++) {
		// 3 X's or O's in a row
		if ( board[i][0] + board[i][1] + board[i][2] == symbol*3) {
			printf("%c Player Wins!\n", symbol);
			return player;
		}
	}
	
	// Check col win
	for (j = 0; j < 3; j++) {
		// 3 X's or O's in a col
		if ( board[0][j] + board[1][j] + board[2][j] == symbol*3) {
			printf("%c Player Wins!\n", symbol);
			return player;
		}
	}
	
	// Check diagonal win
	// 3 X's or O's top left to bottom right
	if ( board[0][0] + board[1][1] + board[2][2] == symbol*3) {
		printf("%c Player Wins!\n", symbol);
		return player;
	}
	// 3 X's or O's bottom left to top right
	if ( board[2][0] + board[1][1] + board[0][2] == symbol*3) {
		printf("%c Player Wins!\n", symbol);
		return player;
	}

	// Check for cat's game
	// By checking if every space is filled
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if ( board[i][j] == ' ') // 1 ' ' means no win yet
				return 0;

	// 3 means cat's game
	puts("Cat's Game!");
	return 3;
}

// Ask user for a row/col value
// Returns the ascii code of what they entered minus 48 ('0')
int get_move() {
	char c = getchar();
	while((getchar())!='\n'); // Clear input buffer
	int val = c - '0';
	return val;
}

// Display the board
void print_board(char board[3][3]) {
	// i = row, j = column
	int i, j;
	// Loop through every element of 3x3 array
	// and print every character + lines to make it look nice
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%c", board[i][j]);
			if (j < 2) // we only want 2 col separators
				putchar('|'); // Separate cols
		}
		if (i < 2) // we only want 2 row separators
			puts("\n-----"); // Separate rows
	}

	putchar('\n');
}

// Asks the given player for a move and determines if it is legal
// returns a number other than 0 if the game is won during that turn
int turn(int player, char board[3][3]) {
	int i, j; // i = rows, j = cols
	int illegal = 1; // 1 if move is illegal, 0 if it is legal
	char symbol; // X or O depending on who the player is

	// Determine the appropriate symbol for the given player
	if (player == 1)
		symbol = 'X';
	else if (player == 2)
		symbol = 'O';

	// Ask for the player's desired move
	// Keep asking unless the move is legal
	do {
		printf("Player %d turn '%c'\n", player, symbol);
		print_board(board);
		puts("Which Row would you like?");
		i = get_move();
		puts("Which Col would you like?");
		j = get_move();

		// Check if move is valid
		// Desired space has to be empty and within the board
		if (board[i-1][j-1] == ' ' && i >= 1 && i <= 3 && j >= 1 && j <= 3) {
			board[i-1][j-1] = symbol;
			illegal = 0;
		}

		if (illegal)
			puts("Illegal Move");
	} while (illegal); // Loop if the player's move is illegal

	return check_win(player, board);
}

int main() {
	// winner will store the player # of the winning player
	// 0 means no one has won yet
	int winner = 0;

	// Initialize the board with every value being a space character
	char board[3][3] = {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
	};

	puts("Welcome to Tic-Tac-Toe");
	puts("======================");

	// Do a turn for player one and two until someone wins or cat's game
	do {
		winner = turn(1, board);
		if (winner) // Exit loop if someone won
			break;
		winner = turn(2, board);
		if (winner) // Exit loop if someone won
			break;
	} while (!winner); // Keep looping while there is no winner

	print_board(board);

	return 0;
}
