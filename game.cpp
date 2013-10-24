#include <stdio.h>
#include <ctype.h>
#include "ConsoleUtil.h"


//MACROS (CONSTANT)
#define BOARD_SIZE 9

//Forward Declarations
void menu();
int main();
void menu_selection(char option);
void play();
void draw_board(char board[BOARD_SIZE][BOARD_SIZE]);


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
		//dump_key_buffer();
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
	char pieces[BOARD_SIZE][BOARD_SIZE];

	int i; 

	draw_board(pieces);
}

void draw_board(char pieces[BOARD_SIZE][BOARD_SIZE]){
	int x;
	int y;
	char board[45][45] =
	{{' ', '_', '_', '_', ' ', ' ', '_', '_', '_', ' ',' ', '_', '_', '_', ' ',' ', '_', '_', '_', ' ',' ', '_', '_', '_', ' ',' ', '_', '_', '_', ' ',' ', '_', '_', '_', ' ',' ', '_', '_', '_', ' ',' ', '_', '_', '_', ' '}};
	for(x = 0; x < 45; x++){
		for(y = 0; y < 2; y++){}
			print_char(x, y, board[y][x]);
	}
	

}