#pragma once
#include "Checker.h"
#include "GUI_Ascii.h"
#include "Player.h"


namespace Checkers{
	class CheckerBoardObj {
		//=============== Public Methods/Members ===============//
		public: 
			CheckerBoardObj() {		
				// Set all empty spaces to NULL
				memset((void *) checkerBoard, 0, sizeof(checkerBoard));
			} //__constructor


			~CheckerBoardObj() {
				delete checkerBoard;
			} //__destructor


			int * checkerMoveOptions(int x, int y) {
				//TODO: Error Handling for out of bounds.
				//checkerDirection directions[8];
				int i = 0, modX, modY;
				int moves[8][3];
				int numDirections = 2;

				checkerColor color;

				if(checkerBoard[y][x] != NULL){
					if(checkerBoard[y][x]->IsKinged()){
						numDirections = 8;
					}
					color = checkerBoard[y][x]->getColor();
					
				
					CheckerObj *nextChecker;
					checkerColor nextColor;
					while (i < numDirections) {
						checkerDirection direction = checkerBoard[y][x]->getDirection(i);
						switch (direction) {
						case NE:
							modX = 1;
							modY = -1;
							if(((y+modY) >= 0) && ((y+modY) <= 8)  && ((x+modX) >= 0) && ((x+modX) <= 8)){
								if (checkerBoard[y+modY][x+modX] == NULL){
									moves[i][0] = y+modY; 
									moves[i][1] = x+modX;
									moves[i][2] = 0;
								} 
								else if(checkerBoard[y+modY][x+modX] != NULL)  {
									nextChecker = checkerBoard[y+modY][x+modX];
									nextColor = nextChecker->getColor();
									if ((nextColor != color) && checkerBoard[y+2*modY][x+2*modX] == NULL && 
										((y+2*modY) >= 0) && ((y+2*modY) <= 8)  && ((x+2*modX) >= 0) && ((x+2*modX) <= 8)) {
										moves[i][0] = y+2*modY; 
										moves[i][1] = x+2*modX;
										moves[i][2] = 1;
									}
								}
							}
							break;
						case NW:
							modX = -1;
							modY = -1;
							if(((y+modY) >= 0) && ((y+modY) <= 8)  && ((x+modX) >= 0) && ((x+modX) <= 8)){
								if (checkerBoard[y+modY][x+modX] == NULL) {
									moves[i][0] = y+modY; 
									moves[i][1] = x+modX;
									moves[i][2] = 0;
								} else if(checkerBoard[y+modY][x+modX] != NULL)  {
									nextChecker = checkerBoard[y+modY][x+modX];
									nextColor = nextChecker->getColor();
									if ((nextColor != color) && checkerBoard[y+2*modY][x+2*modX] == NULL && 
										((y+2*modY) >= 0) && ((y+2*modY) <= 8)  && ((x+2*modX) >= 0) && ((x+2*modX) <= 8)) {
										moves[i][0] = y+2*modY; 
										moves[i][1] = x+2*modX;
										moves[i][2] = 1;
									}
								}
							}
							break;
						case SE:
							modX = 1;
							modY = 1;
							if(((y+modY) >= 0) && ((y+modY) <= 8)  && ((x+modX) >= 0) && ((x+modX) <= 8)){
								if (checkerBoard[y+modY][x+modX] == NULL) {
									moves[i][0] = y+modY; 
									moves[i][1] = x+modX;
									moves[i][2] = 0;
								} else if(checkerBoard[y+modY][x+modX] != NULL)  {
									nextChecker = checkerBoard[y+modY][x+modX];
									nextColor = nextChecker->getColor();
									if ((nextColor != color) && checkerBoard[y+2*modY][x+2*modX] == NULL && 
										((y+2*modY) >= 0) && ((y+2*modY) <= 8)  && ((x+2*modX) >= 0) && ((x+2*modX) <= 8)) {								moves[i][0] = y+2*modY; 
										moves[i][1] = x+2*modX;
										moves[i][2] = 1;
									}
								}
							}
							break;
						case SW:
							modX = -1;
							modY = 1;
							if(((y+modY) >= 0) && ((y+modY) <= 8)  && ((x+modX) >= 0) && ((x+modX) <= 8)){
								if (checkerBoard[y+modY][x+modX] == NULL) {
									moves[i][0] = y+modY; 
									moves[i][1] = x+modX;
									moves[i][2] = 0;
								} else if(checkerBoard[y+modY][x+modX] != NULL)  {
									nextChecker = checkerBoard[y+modY][x+modX];
									nextColor = nextChecker->getColor();
									if ((nextColor != color) && checkerBoard[y+2*modY][x+2*modX] == NULL && 
										((y+2*modY) >= 0) && ((y+2*modY) <= 8)  && ((x+2*modX) >= 0) && ((x+2*modX) <= 8)) {
										moves[i][0] = y+2*modY; 
										moves[i][1] = x+2*modX;
										moves[i][2] = 1;
									}
								}
							}
							break;
						case N:
							modX = 0;
							modY = -1;
							if(((y+modY) >= 0) && ((y+modY) <= 8)  && ((x+modX) >= 0) && ((x+modX) <= 8)){
								if (checkerBoard[y+modY][x+modX] == NULL) {
									moves[i][0] = y+modY; 
									moves[i][1] = x+modX;
									moves[i][2] = 0;
								} else if(checkerBoard[y+modY][x+modX] != NULL)  {
									nextChecker = checkerBoard[y+modY][x+modX];
									nextColor = nextChecker->getColor();
									if ((nextColor != color) && checkerBoard[y+2*modY][x+2*modX] == NULL && 
										((y+2*modY) >= 0) && ((y+2*modY) <= 8)  && ((x+2*modX) >= 0) && ((x+2*modX) <= 8)) {
										moves[i][0] = y+2*modY; 
										moves[i][1] = x+2*modX;
										moves[i][2] = 1;
									}
								}
							}
							break;
						case S:
							modX = 0;
							modY = 1;
							if(((y+modY) >= 0) && ((y+modY) <= 8)  && ((x+modX) >= 0) && ((x+modX) <= 8)){
								if (checkerBoard[y+modY][x+modX] == NULL) {
									moves[i][0] = y+modY; 
									moves[i][1] = x+modX;
									moves[i][2] = 0;
								} else if(checkerBoard[y+modY][x+modX] != NULL)  {
									nextChecker = checkerBoard[y+modY][x+modX];
									nextColor = nextChecker->getColor();
									if ((nextColor != color) && checkerBoard[y+2*modY][x+2*modX] == NULL && 
										((y+2*modY) >= 0) && ((y+2*modY) <= 8)  && ((x+2*modX) >= 0) && ((x+2*modX) <= 8)) {
										moves[i][0] = y+2*modY; 
										moves[i][1] = x+2*modX;
										moves[i][2] = 1;
									}
								}
							}
							break;
						case E:
							modX = 1;
							modY = 0;
							if(((y+modY) >= 0) && ((y+modY) <= 8)  && ((x+modX) >= 0) && ((x+modX) <= 8)){
								if (checkerBoard[y+modY][x+modX] == NULL) {
									moves[i][0] = y+modY; 
									moves[i][1] = x+modX;
									moves[i][2] = 0;
								} else if(checkerBoard[y+modY][x+modX] != NULL) {
									nextChecker = checkerBoard[y+modY][x+modX];
									nextColor = nextChecker->getColor();
									if ((nextColor != color) && checkerBoard[y+2*modY][x+2*modX] == NULL && 
										((y+2*modY) >= 0) && ((y+2*modY) <= 8)  && ((x+2*modX) >= 0) && ((x+2*modX) <= 8)) {
										moves[i][0] = y+2*modY; 
										moves[i][1] = x+2*modX;
										moves[i][2] = 1;
									}
								}
							}
							break;
						case W:
							modX = -1;
							modY = 0;
							if(((y+modY) >= 0) && ((y+modY) <= 8)  && ((x+modX) >= 0) && ((x+modX) <= 8)){
								if (checkerBoard[y+modY][x+modX] == NULL) {
									moves[i][0] = y+modY; 
									moves[i][1] = x+modX;
									moves[i][2] = 0;
								} else if(checkerBoard[y+modY][x+modX] != NULL)  {
									nextChecker = checkerBoard[y+modY][x+modX];
									nextColor = nextChecker->getColor();
									if ((nextColor != color) && checkerBoard[y+2*modY][x+2*modX] == NULL && 
										((y+2*modY) >= 0) && ((y+2*modY) <= 8)  && ((x+2*modX) >= 0) && ((x+2*modX) <= 8)) {
										moves[i][0] = y+2*modY; 
										moves[i][1] = x+2*modX;
										moves[i][2] = 1;
									}
								}
							}
							break;
						default:
							throw UnknownDirection;
							break; //TODO: Error handling - not a direction.
						}
						i++;
					}
				}
				int j, k;
				int l = 0;
				int movesReturn[24];
				for (j = 0; j < 8; j++) {
					for (k = 0; k < 3; k++) {
						if(moves[j][0] >= 0 && moves[j][0] < 9) {
							movesReturn[l] = moves[j][k];
							l++;
						} else {
							movesReturn[l] = -1;
							l++;
						}
					}
				}
				return movesReturn;
			}// checkerMoveOptions

			// TODO: Confirm that these operate correctly
			bool MoveChecker(int originX, int originY, int destinationX, int destinationY) {
				bool result = false;
				checkerColor color;
				if(checkerBoard[originY][originX] != NULL){
					color = checkerBoard[originY][originX]->getColor();
				}
				bool useSpecial = false;
				if(color == green){
					useSpecial = checkerBoard[originY][originX]->Move();
				}
				if(color == green && useSpecial){
					result = true;
				}
				checkerBoard[destinationY][destinationX] = checkerBoard[originY][originX];
				checkerBoard[originY][originX] = NULL;
				return result;
			} //MoveChecker

			// TODO: Confirm that these operate correctly
			int * JumpChecker(int originX, int originY, int destinationX, int destinationY) {
				int killX = destinationX-((destinationX-originX)/2);
				int killY = destinationY-((destinationY-originY)/2);
				int result[4];

				//Special Checking
				if(checkerBoard[killY][killX] != NULL && checkerBoard[killY][killX]->getColor() == black){
					result[0] = checkerBoard[killY][killX]->GetID();
					result[1] = checkerBoard[killY][killX]->getColor();
					if (checkerBoard[killY][killX]->Delete()){
						if(checkerBoard[originY][originX]->getColor() == red && checkerBoard[originY][originX]->IsSpecialAvailable() == true){
							checkerBoard[originY][originX]->UseSpecial();
							result[2] = -1;
							result[3] = -1;
						}
						else{
							result[2] = checkerBoard[originY][originX]->GetID();
							result[3] = checkerBoard[originY][originX]->getColor();
							checkerBoard[originY][originX] = NULL;
						}
						checkerBoard[killY][killX] = NULL;
					}
					checkerBoard[killY][killX] = NULL;
				}
				else if(checkerBoard[killY][killX] != NULL && checkerBoard[killY][killX]->getColor() == red){
					bool specialUsed = checkerBoard[killY][killX]->Delete();
					if(specialUsed){
						result[0] = checkerBoard[killY][killX]->GetID();
						result[1] = checkerBoard[killY][killX]->getColor();
						result[2] = -1;
						result[3] = -1;
						checkerBoard[killY][killX] = NULL;
					}
					else{
						result[0] = -1;
						result[1] = -1;
						result[2] = -1;
						result[3] = -1;
					}
				}
				else if(checkerBoard[killY][killX] != NULL && checkerBoard[killY][killX]->getColor() == green){
					result[0] = checkerBoard[killY][killX]->GetID();
					result[1] = checkerBoard[killY][killX]->getColor();
					result[2] = -1;
					result[3] = -1;
					checkerBoard[killY][killX] = NULL;
				}

				checkerBoard[destinationY][destinationX] = checkerBoard[originY][originX];
				checkerBoard[originY][originX] = NULL;

				return result;
			} //JumpChecker

			
			void AddChecker(int destinationX, int destinationY, CheckerObj *checker) {
				checkerBoard[destinationY][destinationX] = checker;
			}


			void AddPlayersCheckers(int xCords[], int yCords[], CheckerObj *ptr){
				int i=0;
				CheckerObj *temp = ptr;

				while (temp != NULL) {
					AddChecker(xCords[i], yCords[i], temp);
					i++;
					temp = temp->next;
				} //while

				COORD pos = {0, 30};
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			} //AddPlayersCheckers


			void DisplayBoard() {
				// TODO: Update this method to draw each current checker
				guiObj->DisplayBoard();
			} //DisplayBoard

			void DisplayChecker(){
				int x, y;
				int realX, realY;
				for(x = 0; x < 9; x ++){
					for(y = 0; y < 9; y++){
						realX = 2 + (x * 6);
						realY = 3 + (y * 2);
						COORD pos = {realX , realY};
						
						CheckerObj *currentChecker = checkerBoard[y][x];
						if(!currentChecker){
							char checkerSymbol[4] = {'_', '_', '_', '_'};
							guiObj -> DisplayChar(realX, realY, checkerSymbol[0]);
							guiObj -> DisplayChar((realX + 1), realY, checkerSymbol[1]);
							guiObj -> DisplayChar((realX + 2), realY, checkerSymbol[2]);
							guiObj -> DisplayChar((realX + 3), realY, checkerSymbol[3]);
							continue;
						}
						checkerColor color = currentChecker->getColor();
						bool kinged = currentChecker->IsKinged();
						bool special = currentChecker->IsSpecialAvailable();
						char checkerSymbol[4] = {'_', '_', '_', '_'};

						if(color == black && special == true){
							checkerSymbol[0]  = 'B';
						}
						else if(color == black && special == false){
							checkerSymbol[0]  = 'b';
						}
						else if(color == green && special == true){
							checkerSymbol[0] = 'G';
						}
						else if(color == green && special == false){
							checkerSymbol[0] = 'g';
						}
						else if(color == red && special == true){
							checkerSymbol[0] = 'R';
						}
						else if(color == red && special == false){
							checkerSymbol[0] = 'r';
						}
						else {
							checkerSymbol[0] = '_';
						}
						if(kinged == true){
							checkerSymbol[1] = 'K';
						}
						else {
							checkerSymbol[1] = '_';
						}
						checkerSymbol[2] = currentChecker->GetID();


						guiObj -> DisplayChar(realX, realY, checkerSymbol[0]);
						guiObj -> DisplayChar((realX + 1), realY, checkerSymbol[1]);
						guiObj -> DisplayInt((realX + 2), realY, currentChecker->GetID());
					}
				}
			}

			void GetCheckerColor(int x, int y){
				// TODO: Change this so that it returns the color of the object
				//checkerColor result = checkerBoard[x][y] -> getColor();
				//return result;

			}

			void setBoardNull(){
				int i, j;
				for(i = 0; i < 8; i ++){
					for(j = 0; j < 8; j++){
						checkerBoard[i][j] = NULL;
					}
				}
			}

			int * convertToCoords(int id){
				int x, y, j, k;
				for(j = 0; j < 9; j++){
					for(k = 0; k < 9; k++){
						if(checkerBoard[j][k] != NULL){
							int currentID = checkerBoard[j][k]->GetID();
							if(currentID == id){
								y = j;
								x = k;
								break;
							}
						}
					}
				}

				int coords[2];
				coords[0] = y;
				coords[1] = x;
				return coords;
			}

			//Check if a piece is in a position where it should be kinged
			void CheckKings(){
				int blackKingSpaces[9][2] = {{0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5}, {0,6}, {0,7}, {0,8}};
				int redKingSpaces[9][2] = {{8,0}, {8,1}, {8,2}, {8,3}, {8,4}, {8,5}, {8,6}, {8,7}, {8,8}};
				int greenKingSpaces[9][2] = {{0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0}, {8,0}};
				int i = 0;
				for(i = 0; i < 9; i++){
					int x = blackKingSpaces[i][1];
					int y = blackKingSpaces[i][0];
					if(checkerBoard[y][x] != NULL && checkerBoard[y][x]->getColor() == black){
						checkerBoard[y][x]->KingMe();
					}
					x = redKingSpaces[i][1];
					y = redKingSpaces[i][0];
					if(checkerBoard[y][x] != NULL && checkerBoard[y][x]->getColor() == red){
						checkerBoard[y][x]->KingMe();
					}
					x = greenKingSpaces[i][1];
					y = greenKingSpaces[i][0];
					if(checkerBoard[y][x] != NULL && checkerBoard[y][x]->getColor() == green){
						checkerBoard[y][x]->KingMe();
					}
				}
			}



		//=============== Private Methods/Members ===============//
		private:
			CheckerObj *checkerBoard[9][9]; 
	}; //CheckerBoardObj
}