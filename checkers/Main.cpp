#include <stdio.h>
#include "CheckerBoardHeader.h"

#define NUMBER_OF_PLAYERS 3

int main() {
	int numberOfTurns = 0;
	Checkers::CheckerObj* playerList[NUMBER_OF_PLAYERS];
	Checkers::CheckerObj* currentPlayer;
	Checkers::CheckerBoardObj* checkerBoardObj = new Checkers::CheckerBoardObj(NUMBER_OF_PLAYERS);

	// TODO: Add call to CheckerBoardObj class to display menu

	// Handle a full game until 1 or fewer players remain
	while (sizeof(playerList) > 1) {
		// Selects current player by modding remaining players with turn number; i.e., turn 4 in 3 player game will select array[1] (2nd player).
		currentPlayer = playerList[numberOfTurns % sizeof(playerList)];

		// TODO: Prompt user for an action on their turn
		//ActivatePlayer(currentPlayer);
	} //while

	if (1 == sizeof(playerList)) {
		// Last remaining player is the winner
	} else {
		// Black's special power resulted in no one surviving; Game Over!
	} //if-else
} //main