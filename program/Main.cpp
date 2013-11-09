#pragma once
#include <stdio.h>
#include <iostream>
#include "Global.h"
#include "CheckerBoard.h"
#include "GUI_Ascii.h"
#include "Player.h"

using namespace Checkers;

// Forward Declarations
int main();
void PlayGame(int playerCount);
int ActivatePlayer(PlayerObj *currentPlayer);
CheckerObj *CreateNewPlayer();
CheckerBoardObj* checkerBoardObj;
GUI_Ascii *guiObj;


int main() {
	// Initialize variables
	int numberOfTurns = 0;
	char mainMenuSelectionBuffer;
	int playerCount;

	// Instantiate class objects
	guiObj = new GUI_Ascii();

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
	int numPlayers = playerCount;

	// Instantiate class objects
	//CheckerObj playerList[3]; // TODO: Find workaround to instantiate array length via playerCount
	//Players::PlayerObj playerList[playerCount] = new Players::PlayerObj;
	PlayerObj *currentPlayer;
	PlayerObj *playerList;
	playerList = new PlayerObj[playerCount];

	// Add Players
	if (playerCount == 2) {
		new (&playerList[black]) PlayerObj(black);
		new (&playerList[red]) PlayerObj(red);
	} else {
		new (&playerList[black]) PlayerObj(black);
		new (&playerList[red]) PlayerObj(red);
		new (&playerList[green]) PlayerObj(green);
	} //if-else
	
	checkerBoardObj = new CheckerBoardObj(playerList);

	console_activate();
	checkerBoardObj->DisplayBoard();

	// Handle a full game until 1 or fewer players remain
	while (numPlayers > 1) {
		// Selects current player by modding remaining players with turn number; i.e., turn 4 in 3 player game will select array[1] (2nd player)
		for (i = 0; i < playerCount; i++) {
			// Delete player from active list
			if (0 == playerList[i].getNumCheckers()) {
				playerList[i].~PlayerObj();
				numPlayers = numPlayers - 1;
			} //if
		} //for

		// TODO: Check the sizeof part to make sure it is returning array size and not memory size 
		//			Also, evaluate if the currentPlayer variable is necessary. If not, remove it.
		currentPlayer = &playerList[numberOfTurns % sizeof(playerList)];
		ActivatePlayer(currentPlayer);
	} //while

	if (1 == numPlayers) {
		// Last remaining player is the winner
		//CheckerObj winner = playerList[0];
		//checkerBoardObj->DisplayWinner(winner);
	} else {
		// Black's special power resulted in no one surviving; Game Over!
	} //if-else
} //PlayGame


int ActivatePlayer(PlayerObj *currentPlayer) {
	// TODO: Prompt user for an action on their turn. Takes in the player whose turn it is, and the checker board that is in use.
	int id, killCheckerId = NULL;
	int origin_X, origin_Y, destination_X, destination_Y;
	bool isJump;
	
	//GOOOOEY!?! Get origX, origY, destX, destY, isJump
	guiObj->DisplayPlayerMoveMenu();
	guiObj->HandlePlayerMoveMenuResponse();

	// TODO: Replace dummy values with returns from gui prompt
	origin_X = 1;
	origin_Y = 2;
	destination_X = 3;
	destination_Y = 4;

	// TODO: Add a condition to distinguish between moves and jumps
	if (true) {
		// Jump another checker
		killCheckerId = checkerBoardObj->JumpChecker(origin_X, origin_Y, destination_X, destination_Y);
	} else {
		// Move checker to a blank space
		checkerBoardObj->MoveChecker(origin_X, origin_Y, destination_X, destination_Y);
	} //if-else

	return killCheckerId;
} //ActivatePlayer


// TODO: Discern what this function should be doing
int DeletePlayer(PlayerObj list[], int arrayLocation){
	PlayerObj player = list[0]; //TODO:PLEASE FIX
	int numCheckers = player.getNumCheckers();

	if (numCheckers == 0) {

	} //if

	// TODO: Replace dummy return value with actual return
	return 0;
} //DeletePlayer