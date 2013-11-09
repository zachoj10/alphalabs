#pragma once
#include "ConsoleUtil.h"

// MACROS (CONSTANT)
#define LEVEL_WIDTH CONSOLE_WIDTH
#define LEVEL_HEIGHT (CONSOLE_HEIGHT - 1)

namespace Checkers{
	class GUI_Ascii {
		//=============== Public Methods/Members ===============//
		public:
			void DisplayBoard() {
				int x, y;
				char checkerBoard[LEVEL_HEIGHT][LEVEL_WIDTH] =	{
					{' ', ' ', '1', ' ', ' ', ' ', '2', ' ', ' ', ' ', '3', ' ', ' ', ' ', '4', ' ', ' ',' ', '5', ' ', ' ',' ', '6', ' ', ' ',' ', '7', ' ', ' ',' ', '8',' ', ' ', ' ', '9', ' '},
					{' ', ' ', '_', '_', ' ', ' ', '_', '_', ' ', ' ', '_', '_', ' ', ' ', '_', '_', ' ', ' ', '_', '_', ' ', ' ', '_', '_', ' ', ' ', '_', '_', ' ', ' ', '_', '_', ' ', ' ', '_', '_', ' '},
					{' ', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|'},
					{'1', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|'},
					{' ', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|'},
					{'2', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|'},
					{' ', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|'},
					{'3', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|'},
					{' ', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|'},
					{'4', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|'},
					{' ', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|'},
					{'5', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|'},
					{' ', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|'},
					{'6', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|'},
					{' ', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|'},
					{'7', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|'},
					{' ', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|'},
					{'8', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|'},
					{' ', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|', '|', ' ', ' ', '|'},
					{'9', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|', '|', '_', '_', '|'},

				}; //checkerBoard

				for (x = 0; x < LEVEL_WIDTH; x++) {
					for (y = 0; y < LEVEL_HEIGHT; y++) {
						print_char(x , y , checkerBoard[y][x]);
					} //for
				} //for
			} //DisplayBoard


			void DisplayMainMenu() {
				printf("\nMenu Options\n");
				printf("------------------------------------------------------\n");
				printf("p: Play\n");
				printf("q: Quit\n");

				printf("\n\nPlease enter a choice ---> ");
			} //DisplayMainMenu


			void DisplayPlayerCountMenu() {
				std::cout << "\nHow many players? (2-3) ---> ";
			} //DisplayPlayerCountMenu


			void DisplayWelcome() {
				std::cout << "\n\nWelcome to Checkers by AlphaLabs\n";
			} //DisplayWelcome


			void DisplayUserInputError() {
				std::cout << "\n\nError: Please input a valid menu option...\n\n";
			} //DisplayUserInputError


			char HandleMainMenuResponse() {
				char menuSelectionBuffer;

				// Retrieve main menu action
				std::cin >> menuSelectionBuffer;
				return menuSelectionBuffer; 
			} //HandleMainMenuResponse


			int HandlePlayerCountMenuResponse() {
				int playerCount;

				// Retrieve player count
				std::cin.ignore();
				std::cin >> playerCount;
				return playerCount;
			} //HandlePlayerCountMenuResponse


			void DisplayPlayerMoveMenu() {
				// TODO: Prompt user for which checker to move
			} //DisplayPlayerMoveMenu

			int* PieceCoordMenu(){
				int CordX, CordY;
				int result[2];
				DisplayString(0, 20, "What is the X Coordinate of the piece you want to move?");
				do {
					CordX = GetIntInput();
				}
				while(CordX < 1 || CordX > 9); 
				result[0] = CordX;
				DisplayString(0, 21, "\nWhat is the Y Coordinate of the piece you want to move?");
				do {
					CordY = GetIntInput();
				}
				while(CordY < 1 || CordY > 9); 
				result[1] = CordY;
				return result;
			}


			// TODO: Adjust return type as needed depending on how the menu is implemented
			char HandlePlayerMoveMenuResponse() {
				char menuSelectionBuffer;

				// Retrieve player move menu action
				std::cin.ignore();
				std::cin >> menuSelectionBuffer;
				return menuSelectionBuffer;
			} //HandlePlayerMoveMenuResponse

			void DisplayChar(int x, int y, char c){
				COORD pos = {x, y};
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				std::cout << c;
			}

			void DisplayString(int x, int y, const char* str){
				COORD pos = {x , y};
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

				std::cout << str;
			}

			int GetIntInput(){
				int result;
				std::cin >> result;
				return result;
			}

	}; //GUI_Ascii
}