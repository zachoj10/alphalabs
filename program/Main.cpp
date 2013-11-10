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
void ActivatePlayer(PlayerObj *currentPlayer);
CheckerObj *CreateNewPlayer();
CheckerBoardObj* checkerBoardObj;
void StartGame(int players, PlayerObj list[]);



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
	int x, y, i;
	int numPlayers = playerCount;

	// Instantiate class objects
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
	
	// Prepare game elements
	checkerBoardObj = new CheckerBoardObj();
	StartGame(numPlayers, playerList);
	console_activate();
	checkerBoardObj->DisplayBoard();
	checkerBoardObj->DisplayChecker();

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
		currentPlayer = & playerList[numberOfTurns % sizeof(playerList)];
		ActivatePlayer(currentPlayer);
	} //while

	// Final player check to handle black's special power. Bring out 'yer dead!
	// TODO: check all player's for death

	if (1 == numPlayers) {
		// Last remaining player is the winner
		//CheckerObj winner = playerList[0];
		//checkerBoardObj->DisplayWinner(winner);
	} else {
		// Black's special power resulted in no one surviving; Game Over!
	} //if-else
} //PlayGame


void ActivatePlayer(PlayerObj *currentPlayer) {
	int CordX, CordY;
	int *pieceToMove;
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
		while (NULL != currentChecker->next) {
			checkerOptions[numberOfOptions] = currentChecker->GetID();
			numberOfOptions++;
			currentChecker = currentChecker->next;
		} //while
	} //if-else

	// Display all checker options
	guiObj->DisplayPlayerCheckerOptionsMenu(checkerOptions, numberOfOptions);


	// TODO: Change this to prompt for one of the integer options provided
	//			Take that ID and send it to Gareth's method in checkerboard class as CheckerObj
	//Prompt Player For action on their turn
	pieceToMove = guiObj->PieceCoordMenu();
	CordX = pieceToMove[0];
	CordY = pieceToMove[1];

	//moveOptions[0][0] = checkerMoveOptions(CordX, CordY);
	

	int id;
	int killCheckerId[2];
	int origin_X, origin_Y, destination_X, destination_Y;
	bool isJump;
	
	//GOOOOEY!?! Get origX, origY, destX, destY, isJump

	// TODO: Replace dummy values with returns from gui prompt
	origin_X = CordX;
	origin_Y = CordY;
	destination_X = 3;
	destination_Y = 4;

	try {
		int *options = checkerBoardObj->checkerMoveOptions(origin_X - 1, origin_Y - 1);
		int moveOptions[3][8];
		int k, j;
		int l = 0;
		for (k = 0; k < 2; k++) {
			for (j = 0; j < 7; j++) {
				moveOptions[j][k] = options[l];
				l++;
			} //for
		} //for
	} catch(int e){
		if (e == UnknownDirection) {
			std::cerr<<("Unknown Direction Error");
		} //if
	} //try-catch

	guiObj->DisplayPlayerMoveMenu();
	guiObj->HandlePlayerMoveMenuResponse() ;
	// TODO: Add a condition to distinguish between moves and jumps

	if (true) {
		// Jump another checker
		int i = 0;
		
		int *kills = checkerBoardObj->JumpChecker(origin_X, origin_Y, destination_X, destination_Y);
		while(i < 2){
			if(kills[i] != -1){
				currentPlayer->KillChecker(kills[i]);
			}
			i++;
		}
	} else {
		// Move checker to a blank space
		if(checkerBoardObj->MoveChecker(origin_X, origin_Y, destination_X, destination_Y)){
			currentPlayer->AddPieceToList();
			checkerBoardObj->AddChecker(origin_X, origin_Y, currentPlayer->GetHead()); 
		}
	} //if-else
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

void StartGame(int players, PlayerObj list[]){
	CheckerObj *temp;
	int BlackXCoords[7] = {1, 2, 3, 4, 5, 6, 7};
	int BlackYCoords[7] = {8, 7, 8, 7, 8, 7, 8};
	int RedXCoords[7] = {1, 2, 3, 4, 5, 6, 7};
	int RedYCoords[7] = {0, 1, 0, 1, 0, 1, 0};
	int GreenXCoords[7] = {8, 7, 8, 7, 8, 7, 8};
	int GreenYCoords[7] = {1, 2, 3, 4, 5, 6, 7};
	if(players == 2){
		temp = list[black].GetHead();
		checkerBoardObj->AddPlayersCheckers(BlackXCoords, BlackYCoords, temp);
		temp = list[red].GetHead();
		checkerBoardObj->AddPlayersCheckers(RedXCoords, RedYCoords, temp);
	}
	else {
		temp = list[black].GetHead();
		checkerBoardObj->AddPlayersCheckers(BlackXCoords, BlackYCoords, temp);
		temp = list[red].GetHead();
		checkerBoardObj->AddPlayersCheckers(RedXCoords, RedYCoords, temp);
		temp = list[green].GetHead();
		checkerBoardObj->AddPlayersCheckers(GreenXCoords, GreenYCoords, temp);
	}

}

