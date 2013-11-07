#include <stdio.h>
#include <iostream>
#include "CheckerBoard.h"
#include "GUI_Ascii.h"
#include "Player.h"

using namespace Checkers;

// Forward Declarations
int main();
void PlayGame(int playerCount);
CheckerObj *CreateNewPlayer();
void ActivatePlayer(CheckerObj *currentPlayer);
typedef enum {black, red, green} checkerColor;
typedef enum {SE, SW, NE, NW, N, S, E, W} checkerDirection;
CheckerBoardObj* checkerBoardObj;


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
	int numPlayers = playerCount;

	// Instantiate class objects
	//CheckerObj playerList[3]; // TODO: Find workaround to instantiate array length via playerCount
	//Players::PlayerObj playerList[playerCount] = new Players::PlayerObj;
	PlayerObj *playerList[3];
	*playerList = new PlayerObj[playerCount];
	PlayerObj *currentPlayer;

	// Add Players
	if(playerCount == 2){
		playerList[black] = new PlayerObj(black);
		playerList[red] = new PlayerObj(red);
	}
	else{
		playerList[black] = new PlayerObj(black);
		playerList[red] = new PlayerObj(red);
		playerList[green] = new PlayerObj(green);
	}
	
	checkerBoardObj = new CheckerBoardObj(playerList);

	console_activate();
	checkerBoardObj->DisplayBoard();

	// Handle a full game until 1 or fewer players remain
	while (numPlayers > 1) {
		// Selects current player by modding remaining players with turn number; i.e., turn 4 in 3 player game will select array[1] (2nd player)
		for(i = 0; i < playerCount; i++){
			if(playerList[i]->getNumCheckers == 0){
				playerList[i] = NULL;
				numPlayers = numPlayers - 1;
			}
		}

		currentPlayer = playerList[numberOfTurns % sizeof(playerList)];
		//ActivatePlayer(currentPlayer);
	} //while

	if (1 == numPlayers) {
		// Last remaining player is the winner
		//CheckerObj winner = playerList[0];
		//checkerBoardObj->DisplayWinner(winner);
	} else {
		// Black's special power resulted in no one surviving; Game Over!
	} //if-else
} //PlayGame


CheckerObj *CreateNewPlayer() {
	// TODO: Add cases for three different color creations
	checkerColor color = black;
	
	return new CheckerObj;
} //CreateNewPlayer


void ActivatePlayer(PlayerObj player, CheckerBoardObj* cb) {
	// TODO: Prompt user for an action on their turn. Takes in the player whose turn it is, and the checker board that is in use.
	CheckerObj* obj;
	int id, killID, origX, origY, destX, destY;
	bool isJump;
	//GOOOOEY!?! Get origX, origY, destX, destY, isJump
	killID = cb->MoveChecker(origX, origY, destX, destY, isJump);
	//Check Specials
	player.killChecker(killID);
} //ActivatePlayer

int DeletePlayer(PlayerObj list[], int arrayLocation){
	PlayerObj player = list[
	int numCheckers = player.getNumCheckers;
	if(numCheckers == 0){


	}

}
