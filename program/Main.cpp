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
void ActivatePlayer(PlayerObj *currentPlayer,  PlayerObj *playerList, int playerCount);
CheckerObj *CreateNewPlayer();
CheckerBoardObj* checkerBoardObj;
void StartGame(int players, PlayerObj piecesToKill[]);
void RemoveCheckers(PlayerObj *playerList, int kills[]);


int main() {
	// Initialize variables
	int numberOfTurns = 0;
	char mainMenuSelectionBuffer;
	int playerCount;

	// Initialize console settings
	SMALL_RECT windowSize = {0, 0, 79, 40};
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);
	//SetConsoleTitle("Checkers by AlphaLabs");

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
	int i;
	int numberOfActivePlayers = playerCount;

	// Instantiate class objects
	PlayerObj *currentPlayer = NULL;
	PlayerObj *winningPlayer = NULL;
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
	
	// Prepare game elements
	checkerBoardObj = new CheckerBoardObj();
	StartGame(numberOfActivePlayers, playerList);
	console_activate();
	checkerBoardObj->DisplayBoard();
	checkerBoardObj->DisplayChecker();

	// Handle a full game until 1 or fewer players remain
	while (numberOfActivePlayers > 1) {
		// Selects current player by modding remaining players with turn number; i.e., turn 4 in 3 player game will select array[1] (2nd player)
		currentPlayer = &playerList[numberOfTurns % playerCount];
		numberOfTurns++;
		
		// Check if player is still in the game
		if (currentPlayer->active) {
			// Check if this is the player's first turn without any checkers 
			if (0 == currentPlayer->getNumCheckers()) {
				// Deactivate the player and skip turn
				currentPlayer->active = false;
				numberOfActivePlayers--;
				continue;
			} //if

			ActivatePlayer(currentPlayer, playerList, playerCount);
			checkerBoardObj->DisplayChecker();
		} //if
	} //while

	// Final player check to handle black's special power. Bring out 'yer dead!
	for (i = 0; i < playerCount; i++) {
		if (playerList[i].active) {
			if (0 == playerList[i].getNumCheckers()) {
				// This one died before their time...
				currentPlayer->active = false;
				numberOfActivePlayers = numberOfActivePlayers - 1;
			} else {
				// We have a winner!
				winningPlayer = &playerList[i];
			} //if-else
		} //if
	} //for

	// Display game outcome and winner
	if (1 == numberOfActivePlayers) {
		// Last remaining player is the winner
		guiObj->DisplayGameOver_Winner(checkerColorStrings[winningPlayer->getColor()]);
	} else {
		// Black's special power resulted in no one surviving; Draw!
		guiObj->DisplayGameOver_Draw();
	} //if-else

	// Clean up after the current game
	delete[] playerList;
} //PlayGame


void ActivatePlayer(PlayerObj *currentPlayer, PlayerObj *playerList, int playerCount) {
	try {
	int numberOfOptions = 0, checkerOptions[14];
	checkerColor playerColor = currentPlayer->getColor();
	CheckerObj *currentChecker = currentPlayer->GetHead();
	
	// Collect all checker options
	if (1 == currentPlayer->getNumCheckers()) {
		// Handle case of single checker
		checkerOptions[numberOfOptions] = currentChecker->GetID();
		numberOfOptions++;
	} else {
		// Handle case of multiple checkers
		while (NULL != currentChecker) {
			checkerOptions[numberOfOptions] = currentChecker->GetID();
			numberOfOptions++;
			currentChecker = currentChecker->next;
		} //while
	} //if-else

	// Display all checker options

		
			int origin_X, origin_Y, destination_X, destination_Y;
			int moveStuff[24];
			int moveDestination[3];
			bool isJump = false;	
			int *moveLocation;
			int i;
		do {
			guiObj->DisplayPlayerCheckerOptionsMenu(checkerOptions, numberOfOptions, checkerColorStrings[currentPlayer->getColor()]);
			int moveOption = guiObj->HandlePlayerCheckerOptions(checkerOptions, numberOfOptions);
			int *coords = checkerBoardObj->convertToCoords(moveOption);
			origin_Y = coords[0];
			origin_X = coords[1];

			int *options = checkerBoardObj->checkerMoveOptions(origin_X, origin_Y);

			for (i = 0; i < 24; i++) {
				moveStuff[i] = options[i];
			} //for

			guiObj->DisplayMoveOptions(moveStuff);
			moveLocation = guiObj->HandlePlayerMoveOptions(moveStuff);
		} while (moveLocation == NULL); //Do this until we have a checker with valid moves.
		
		for(i = 0; i < 3; i++) {
			moveDestination[i] = moveLocation[i];
		} //for

		destination_X = moveDestination[1];
		destination_Y = moveDestination[0];

		if (moveDestination[2] == 1) {
			isJump = true;
		} //if
	

	if (isJump) {
		// Jump another checker
		int counter;
		
		int piecesToKill[4];
		int *kills = checkerBoardObj->JumpChecker(origin_X, origin_Y, destination_X, destination_Y);
		piecesToKill[0] = kills[0];
		piecesToKill[1] = kills[1];
		piecesToKill[2] = kills[2];
		piecesToKill[3] = kills[3];

		RemoveCheckers(playerList, piecesToKill);
		
	} else {
		// Move checker to a blank space
		bool greenSpecial = checkerBoardObj->MoveChecker(origin_X, origin_Y, destination_X, destination_Y);

		if (greenSpecial) {
			// Activate Green's special power
			currentPlayer->AddPieceToList();
			checkerBoardObj->AddChecker(origin_X, origin_Y, currentPlayer->GetHead()); 
		} //if
	} //if-else

	checkerBoardObj->CheckKings();
	checkerBoardObj->DisplayChecker();
	} catch (int e) {
		if (e == UnknownDirection) {
			std::cerr<<("Unknown Direction Error");
		} //if
	} //try-catch
} //ActivatePlayer


void StartGame(int players, PlayerObj *list){
	CheckerObj *temp;
	int BlackXCoords[7] = {1, 2, 3, 4, 5, 6, 7};
	int BlackYCoords[7] = {8, 7, 8, 7, 8, 7, 8};
	int RedXCoords[7] = {1, 2, 3, 4, 5, 6, 7};
	int RedYCoords[7] = {0, 1, 0, 1, 0, 1, 0};
	int GreenXCoords[7] = {8, 7, 8, 7, 8, 7, 8};
	int GreenYCoords[7] = {1, 2, 3, 4, 5, 6, 7};

	if (players == 2) {
		temp = list[black].GetHead();
		checkerBoardObj->AddPlayersCheckers(BlackXCoords, BlackYCoords, temp);
		temp = list[red].GetHead();
		checkerBoardObj->AddPlayersCheckers(RedXCoords, RedYCoords, temp);
	} else {
		temp = list[black].GetHead();
		checkerBoardObj->AddPlayersCheckers(BlackXCoords, BlackYCoords, temp);
		temp = list[red].GetHead();
		checkerBoardObj->AddPlayersCheckers(RedXCoords, RedYCoords, temp);
		temp = list[green].GetHead();
		checkerBoardObj->AddPlayersCheckers(GreenXCoords, GreenYCoords, temp);
	} //if-else
} //StartGame

void RemoveCheckers(PlayerObj *playerList, int piecesToKill[]){
	int i;
	int killList[4];
	killList[0] = piecesToKill[0];
	killList[1] = piecesToKill[1];
	killList[2] = piecesToKill[2];
	killList[3] = piecesToKill[3];
	for (i= 0; i < 3; i += 2) {
		int color = killList[(i+1)];
		int id = killList[i];
		if(killList[i] == -1) {
		} //if
		else if(color == 0){
			playerList[black].KillChecker(id);
		}
		else if(color == 1){
			playerList[red].KillChecker(id);
		}
		else if(color == 2){
			playerList[green].KillChecker(id);
		}
	} //for
}
