#include <stdio.h>
#include <iostream>
#include "CheckerBoard.h"
#include "GUI_Ascii.h"

using namespace Checkers;

// Forward Declarations
int main();
void PlayGame(int playerCount);
CheckerObj *CreateNewPlayer();
void ActivatePlayer(CheckerObj *currentPlayer);

int main() {
	// Initialize variables
	int numberOfTurns = 0;
	char mainMenuSelectionBuffer;
	int playerCount;

	// Instantiate class objects
	GUI_Ascii *guiObj = new GUI_Ascii();

	guiObj->DisplayWelcome();

	do {
		guiObj->DisplayMainMenu();
		mainMenuSelectionBuffer = guiObj->HandleMainMenuResponse();
		
		// Handle main menu selection
		switch (mainMenuSelectionBuffer) {
			case 'p':
				// Play a new game

				// Get player count
				guiObj->DisplayPlayerCountMenu();
				playerCount = guiObj->HandlePlayerCountMenuResponse();

				// Check player boundaries
				if (2 > playerCount || 3 < playerCount) {
					guiObj->DisplayUserInputError();
				} else {
					PlayGame(playerCount);
				} //if-else
			break;

			case 'q':
				// Do nothing
			break;

			default:
				// Invalid input
				guiObj->DisplayUserInputError();
			break;
		} //switch

	} while ('q' != mainMenuSelectionBuffer);
} //main

void PlayGame(int playerCount) {
	// Initialize variables
	int numberOfTurns = 0;
	char key_pressed = ' ';
	int x, y, i;

	// Instantiate class objects
	//CheckerObj playerList[3]; // TODO: Find workaround to instantiate array length via playerCount
	CheckerObj* playerList = new CheckerObj[playerCount];
	CheckerObj *currentPlayer;

	// Add Players
	for (i = 0; i < playerCount - 1; i++) {
		playerList[i].next = CreateNewPlayer();
	} //for

	CheckerBoardObj* checkerBoardObj = new CheckerBoardObj(playerList);

	console_activate();
	checkerBoardObj->DisplayBoard();

	// Handle a full game until 1 or fewer players remain
	while (sizeof(playerList) > 1) {
		// Selects current player by modding remaining players with turn number; i.e., turn 4 in 3 player game will select array[1] (2nd player)
		currentPlayer = &playerList[numberOfTurns % sizeof(playerList)];
		ActivatePlayer(currentPlayer);
	} //while

	if (1 == sizeof(playerList)) {
		// Last remaining player is the winner
	} else {
		// Black's special power resulted in no one surviving; Game Over!
	} //if-else
} //PlayGame


CheckerObj *CreateNewPlayer() {
	// TODO: Add cases for three different color creations
	enum {Black, Red, Green} checkerColors;

	return new CheckerObj;
} //CreateNewPlayer


void ActivatePlayer(CheckerObj *currentPlayer) {
	// TODO: Prompt user for an action on their turn
} //ActivatePlayer