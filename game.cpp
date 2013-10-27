#include <stdio.h>
#include <ctype.h>
#include "ConsoleUtil.h"
#include <iostream>

using namespace std;

//MACROS (CONSTANT)
#define LEVEL_WIDTH CONSOLE_WIDTH
#define LEVEL_HEIGHT (CONSOLE_HEIGHT -1)

//Forward Declarations
void menu();
int main();
void menu_selection(char option);
void play();
void draw_board();
void addPiece(char key_pressed, int x, int y);
void movePiece(int initialX, int initialY, int finalX, int finalY);
void addPlayers();

char pieces[9][9];
char activePlayers[3][10];

void menu()
{
	printf("\nMenu Options\n");
	printf("------------------------------------------------------\n");
	printf("p: Play\n");
	printf("q: Quit\n");

	printf("\n\nPlease enter a choice ---> "); 
}


int main()
{
	char input_buffer;

	printf("\n\nWelcome to Checkers by AlphaLabs\n");


	//menu and input loop
	do
	{
		menu();

		input_buffer = tolower(getchar()); 
		dump_key_buffer();
		menu_selection(input_buffer);
	} 
	while (input_buffer != 'q');

}

void menu_selection(char option)
{
	switch(option)
	{
	case 'p':
		printf("Welcome to Your Game of Checkers\n");
		play();
		break;

	case 'q':
		// main loop will take care of this.
		break;

	default:
		printf("\nError: Invalid Input.  Please try again..."); 
		break;
	}
}


void play(){
	char key_pressed = ' ';
	int x, y;

	int i; 
	/*for(i = 0; i < BOARD_SIZE; i++){
		pieces[0][i] = ' ';
	}*/

	console_activate();

	addPlayers();

	draw_board();

	

	while(key_pressed != 'q'){

		print_string(0, 20, "                 ");
		print_string(0, 21, "                      ");
		print_string(0, 22, "                      ");
		print_string(0, 20, "Enter color: ");
		std::cin >> key_pressed;

	}
}

void draw_board(){
	int x;
	int y;
	char board[LEVEL_HEIGHT][LEVEL_WIDTH] =
	{{' ', '_', ' ', ' ', '_', ' ', ' ', '_', ' ', ' ', '_', ' ', ' ', '_', ' ', ' ', '_', ' ', ' ', '_', ' ', ' ', '_', ' ', ' ', '_', ' '},
	 {'|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|'},
	 {'|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|'},
	 {'|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|'},
	 {'|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|'},
	 {'|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|'},
	 {'|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|'},
	 {'|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|'},
	 {'|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|'},
	 {'|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|'},
	 {'|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|'},
	 {'|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|'},
	 {'|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|'},
	 {'|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|'},
	 {'|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|'},
	 {'|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|'},
	 {'|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|'},
	 {'|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|', '|', ' ', '|'},
	 {'|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|', '|', '_', '|'}};
	for(x = 0; x < LEVEL_WIDTH; x++){
		for(y = 0; y < LEVEL_HEIGHT; y++){
			print_char(x , y , board[y][x]);
		}
	}
}

void addPiece(char key_pressed, int x, int y){
	int boardX, boardY;
	boardX = 1 + 3 * (x-1);
	x = x - 1;
	boardY = 2 * y;
	y = y - 1;
	pieces[y][x] = key_pressed;
	print_char(boardX, boardY, key_pressed);
}

void movePiece(int initialX, int initialY, int finalX, int finalY){
	int boardX, boardY;
	boardX = 1 + 3 * (initialX - 1);
	boardY = 2 * initialY;
	print_char(boardX, boardY, '_');
	boardX = 1 + 3 * (finalX - 1);
	boardY = 2 * finalY;
	print_char(boardX, boardY, pieces[initialY - 1][initialX - 1]);
	pieces[finalY - 1][finalX - 1] = pieces[initialY - 1][initialX - 1];
}

void addPlayers(){
	int numPlayers;
	std::cout << "How many players are there?";
	std::cin >> numPlayers;
	if (numPlayers == 3){
		std::cout << "The three color options are Black, Green, and Red";
		std::cout << "\nPlease enter the color for player 1: ";
		std::cin >> activePlayers[0];
		std::cout << "\nPlease enter the color for player 2: ";
		std::cin >> activePlayers[1];
		std::cout << "\nPlease enter the color for player 3: ";
		std::cin >> activePlayers[2];
	}
	else {
		std::cout << "The two color options are Black and Red";
		std::cout << "\nPlease enter the color for player 1: ";
		std::cin >> activePlayers[0];
		std::cout << "\nPlease enter the color for player 2: ";
		std::cin >> activePlayers[1];
		strcpy(activePlayers[2], "\0");
	}
}

