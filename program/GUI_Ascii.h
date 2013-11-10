#pragma once
#include <sstream>
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


			void DisplayGreenPlayerSpecialMenu() {
				std::cout << "\nDo you want to use your special? (y/n) --> ";
			} //DisplayGreenPlayerSpecialMenu


			char HandleGreenPlayerSpecialMenuResponse() {
				char menuSelectionBuffer;

				// Retrieve green player special menu action
				std::cin.ignore();
				std::cin >> menuSelectionBuffer;
				return menuSelectionBuffer;
			} //HandleGreenPlayerSpecialMenuResponse


			void DisplayMoveOptions(int options[]){
				//int realOptions[24] = options;
				int moveOptions[3][8];
				int k, j;
				int l = 0;
				int optionNumber = 1;
				int i = 0;
				char option;
				int x = 1, y = 25;
				for (k = 0; k < 3; k++) {
					for (j = 0; j < 8; j++) {
						moveOptions[j][k] = options[l];
						l++;
					}
				}

				COORD pos = {x , y};
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

				std::cout << sizeof(options);
				std::cout << optionNumber << ". Move to " << options[0] << "," << options[1];
				/*while(moveOptions[j][k] < 0 || moveOptions[j][k] > 9){
					if(moveOptions[2][i] == 1){
						std::cout << optionNumber << ". Jump to " << moveOptions[0][i] << "," << moveOptions[1][i];
					}
					else{
					//else if(moveOptions[2][i] == 0){
						std::cout << optionNumber << ". Move to " << moveOptions[0][i] << "," << moveOptions[1][i];
					}
					i++;
					optionNumber++;
					y = y++;
					COORD pos = {x , y};
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				}*/
			}


			void DisplayPlayerCheckerOptionsMenu(int checkerOptions[], int numberOfOptions) {
				int i;
				char *displayPointer;
				std::string outputString;

				DisplayString(0, 21, "Which checker would you like to move?");

				for (i = 0; i < numberOfOptions; i++) {
					// Format the option display string
					std::stringstream streamBuffer;
					streamBuffer << i + 1 << ") " << checkerOptions[i];
					outputString = streamBuffer.str();
					displayPointer = (char*)outputString.c_str();

					DisplayString(0, 22 + i, displayPointer);
				} //for

				DisplayString(0, 23 + i, "--> ");
			} //DisplayPlayerCheckerOptionsMenu


			void DisplayGameOver_Winner(char winningColor[]) {
				char *displayPointer;
				std::string outputString;

				// Format the display string
				std::stringstream streamBuffer;
				streamBuffer << "The " << winningColor << " player has won!";
				outputString = streamBuffer.str();
				displayPointer = (char*)outputString.c_str();

				DisplayString(0, 21, displayPointer);
			} //DisplayGameOver_Winner


			void DisplayGameOver_Draw() {
				char *displayPointer;
				std::string outputString;

				// Format the display string
				std::stringstream streamBuffer;
				streamBuffer << "The Black player has blown up the last checker on the board, resulting in a draw!";
				outputString = streamBuffer.str();
				displayPointer = (char*)outputString.c_str();

				DisplayString(0, 21, displayPointer);
			} //DisplayGameOver_Winner
	}; //GUI_Ascii
}