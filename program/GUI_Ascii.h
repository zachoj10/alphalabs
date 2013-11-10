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
					{' ', ' ', '1', ' ', ' ', ' ', ' ', ' ', '2', ' ', ' ', ' ', ' ', ' ', '3', ' ', ' ', ' ', ' ', ' ', '4', ' ', ' ', ' ', ' ',' ', '5', ' ', ' ', ' ', ' ',' ', '6', ' ', ' ', ' ', ' ',' ', '7', ' ', ' ', ' ', ' ',' ', '8',' ', ' ', ' ', ' ', ' ', '9', ' '},
					{' ', ' ', '_', '_', '_', '_', ' ', ' ', '_', '_', '_', '_', ' ', ' ', '_', '_', '_', '_', ' ', ' ', '_', '_', '_', '_', ' ', ' ', '_', '_', '_', '_', ' ', ' ', '_', '_', '_', '_', ' ', ' ', '_', '_', '_', '_', ' ', ' ', '_', '_', '_', '_', ' ', ' ', '_', '_', '_', '_', ' '},
					{' ', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|'},
					{'1', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|'},
					{' ', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|'},
					{'2', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|'},
					{' ', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|'},
					{'3', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|'},
					{' ', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|'},
					{'4', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|'},
					{' ', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|'},
					{'5', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|'},
					{' ', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|'},
					{'6', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|'},
					{' ', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|'},
					{'7', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|'},
					{' ', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|'},
					{'8', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|'},
					{' ', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|'},
					{'9', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|', '|', '_', '_', '_', '_', '|'}
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

			/*int* PieceCoordMenu(){
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
			}*/


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

			void DisplayInt(int x, int y, int i){
				COORD pos = {x, y};
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
				std::cout << i;
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
				clearConsole();
				std::cout << options[3];
				//int realOptions[24] = options;
				int moveOptions[8][3];
				int k, j;
				int l = 0;
				int optionNumber = 1;
				int i = 0;
				char option;
				int x = 1, y = 20;
				for (k = 0; k < 8; k++) {
					for (j = 0; j < 3; j++) {
						moveOptions[k][j] = options[l];
						l++;
					}
				}

				COORD pos = {0 , y};
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

				//std::cout << sizeof(options);
				//std::cout << optionNumber << ". Move to " << options[0] << "," << options[1];

				for(j = 0; j < 24; j+=2){
					//if(moveOptions[j][0] != -858993460){
					if(options[j] != -1) {
						if(options[j + 2] == 1){
							std::cout << optionNumber << ". Jump to " << options[j-1] << "," << options[j];
						}
						else{
						//else if(moveOptions[2][i] == 0){
							std::cout << optionNumber << ". Move to " << options[j-1] << "," << options[j];
						}
						j++;
						optionNumber++;
						y = y++;
						COORD pos = {0 , y};
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					}
				}
				
			}


			void DisplayPlayerCheckerOptionsMenu(int checkerOptions[], int numberOfOptions) {
				clearConsole();
				int i;
				char *displayPointer;
				std::string outputString;
				int options;

				DisplayString(0, 21, "Which checker would you like to move?");

				//Convert ID to Coordinates
			
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

			int HandlePlayerCheckerOptions(int checkerOptions[]) {
				int checkerSelectionBuffer;
				
				//Retrieve checker seletion
				std::cin.ignore();
				std::cin >> checkerSelectionBuffer;
				int checkerID = checkerOptions[checkerSelectionBuffer - 1];
				return checkerID;
			} 

			int * HandlePlayerMoveOptions(int moveOptions[]) {
				int checkerSelectionBuffer;
				
				//Retrieve checker seletion
				std::cin.ignore();
				std::cin >> checkerSelectionBuffer;
				int optionSelected[3];
				optionSelected[0] = moveOptions[3 * checkerSelectionBuffer];
				optionSelected[1] = moveOptions[3 * checkerSelectionBuffer + 1];
				optionSelected[2] = moveOptions[3 * checkerSelectionBuffer + 2];

				return optionSelected;
			} 

			void clearConsole(){
				int i;
				for(i = 0; i < 20; i++){
					DisplayString(0, 20 + i, "                                                                                       ");
				}
			}
	}; //GUI_Ascii
}