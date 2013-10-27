#include <stdio.h>
#include <iostream>
#include "CheckerBoard.h"
#include "GUI_Ascii.h"

using namespace Checkers;

// Forward Declarations
int main();
void PlayGame(int playerCount);

int main() {
	// Initialize variables
	int numberOfTurns = 0;
	char menuSelectionBuffer;
	int playerCount;

	// Instantiate class objects
	GUI_Ascii* guiObj = new GUI_Ascii();

	std::cout << "\n\nWelcome to Checkers by AlphaLabs\n";

	do {
		guiObj->DisplayMenu();
		std::cin.get(menuSelectionBuffer);
		
		// Handle main menu selection
		switch (menuSelectionBuffer) {
			case 'p':
				// Play a new game
				std::cout << "\nWelcome to Your Game of Checkers\n";
				std::cout << "How many players?\n";

				// Retrieve player count and convert to integer
				// TODO: Investigate buffer issue that does not allow user input
				std::cin.get(menuSelectionBuffer);
				playerCount = (int)menuSelectionBuffer;

				PlayGame(playerCount);
			break;

			case 'q':
				// Do nothing
			break;

			default:
				std::cout << "Error: Please input a valid menu option...\n";
			break;
		} //switch

	} while ('q' != menuSelectionBuffer);
} //main

void PlayGame(int playerCount) {
	// Initialize variables
	int numberOfTurns = 0;

	// Instantiate class objects
	CheckerObj** playerList = new CheckerObj*[playerCount];
	CheckerObj* currentPlayer;
	CheckerBoardObj* checkerBoardObj = new CheckerBoardObj(playerCount);

	// Handle a full game until 1 or fewer players remain
	while (sizeof(playerList) > 1) {
		// Selects current player by modding remaining players with turn number; i.e., turn 4 in 3 player game will select array[1] (2nd player)
		currentPlayer = playerList[numberOfTurns % sizeof(playerList)];

		// TODO: Prompt user for an action on their turn
		//ActivatePlayer(currentPlayer);
	} //while

	if (1 == sizeof(playerList)) {
		// Last remaining player is the winner
	} else {
		// Black's special power resulted in no one surviving; Game Over!
	} //if-else
} //PlayGame