#pragma once
#include "Checker.h"
#include "GUI_Ascii.h"
#include "Player.h"


namespace Checkers{
	class CheckerBoardObj {
		//=============== Public Methods/Members ===============//
		public: 
			CheckerBoardObj() {		
				// Instantiate class objects
				guiObj = new GUI_Ascii();
				memset((void *) checkerBoard, 0, sizeof(checkerBoard));
			} //__constructor


			~CheckerBoardObj() {
				// TODO: Add memory freeing commands
			} //__destructor


			int* checkerMoveOptions(int x, int y) {
				//TODO: Error Handling for out of bounds.
				checkerDirection directions[8];
				int i = 0, modX, modY;
				int moves[8][3];
				int numDirections = 2;
				if(checkerBoard[y][x]->IsKinged()){
					numDirections = 8;
				}
				checkerColor color = checkerBoard[y][x]->getColor();
				CheckerObj *nextChecker;
				checkerColor nextColor;
				while (i < numDirections) {
					switch (checkerBoard[y][x]->getDirection(i)) {
					case NE:
						modX = 1;
						modY = -1;
						if (checkerBoard[y+modY][x+modX] == NULL) {
							moves[i][0] = y+modY; 
							moves[i][1] = x+modX;
							moves[i][2] = 0;
						} 
						else {
							nextChecker = checkerBoard[y+modY][x+modX];
							nextColor = nextChecker->getColor();
							if ((nextColor != color) && checkerBoard[y+2*modY][x+2*modX] == NULL) {
								moves[i][0] = y+2*modY; 
								moves[i][1] = x+2*modX;
								moves[i][2] = 1;
							}
						}
						break;
					case NW:
						modX = -1;
						modY = -1;
						if (checkerBoard[y+modY][x+modX] == NULL) {
							moves[i][0] = y+modY; 
							moves[i][1] = x+modX;
							moves[i][2] = 0;
						} else {
							nextChecker = checkerBoard[y+modY][x+modX];
							nextColor = nextChecker->getColor();
							if ((nextColor != color) && checkerBoard[y+2*modY][x+2*modX] == NULL) {
								moves[i][0] = y+2*modY; 
								moves[i][1] = x+2*modX;
								moves[i][2] = 1;
							}
						}
						break;
					case SE:
						modX = 1;
						modY = 1;
						if (checkerBoard[y+modY][x+modX] == NULL) {
							moves[i][0] = y+modY; 
							moves[i][1] = x+modX;
							moves[i][2] = 0;
						} else {
							nextChecker = checkerBoard[y+modY][x+modX];
							nextColor = nextChecker->getColor();
							if ((nextColor != color) && checkerBoard[y+2*modY][x+2*modX] == NULL) {								moves[i][0] = y+2*modY; 
								moves[i][1] = x+2*modX;
								moves[i][2] = 1;
							}
						}
						break;
					case SW:
						modX = -1;
						modY = 1;
						if (checkerBoard[y+modY][x+modX] == NULL) {
							moves[i][0] = y+modY; 
							moves[i][1] = x+modX;
							moves[i][2] = 0;
						} else {
							nextChecker = checkerBoard[y+modY][x+modX];
							nextColor = nextChecker->getColor();
							if ((nextColor != color) && checkerBoard[y+2*modY][x+2*modX] == NULL) {
								moves[i][0] = y+2*modY; 
								moves[i][1] = x+2*modX;
								moves[i][2] = 1;
							}
						}
						break;
					case N:
						modX = 0;
						modY = -1;
						if (checkerBoard[y+modY][x+modX] == NULL) {
							moves[i][0] = y+modY; 
							moves[i][1] = x+modX;
							moves[i][2] = 0;
						} else {
							nextChecker = checkerBoard[y+modY][x+modX];
							nextColor = nextChecker->getColor();
							if ((nextColor != color) && checkerBoard[y+2*modY][x+2*modX] == NULL) {
								moves[i][0] = y+2*modY; 
								moves[i][1] = x+2*modX;
								moves[i][2] = 1;
							}
						}
						break;
					case S:
						modX = 0;
						modY = 1;
						if (checkerBoard[y+modY][x+modX] == NULL) {
							moves[i][0] = y+modY; 
							moves[i][1] = x+modX;
							moves[i][2] = 0;
						} else {
							nextChecker = checkerBoard[y+modY][x+modX];
							nextColor = nextChecker->getColor();
							if ((nextColor != color) && checkerBoard[y+2*modY][x+2*modX] == NULL) {
								moves[i][0] = y+2*modY; 
								moves[i][1] = x+2*modX;
								moves[i][2] = 1;
							}
						}
						break;
					case E:
						modX = 1;
						modY = 0;
						if (checkerBoard[y+modY][x+modX] == NULL) {
							moves[i][0] = y+modY; 
							moves[i][1] = x+modX;
							moves[i][2] = 0;
						} else {
							nextChecker = checkerBoard[y+modY][x+modX];
							nextColor = nextChecker->getColor();
							if ((nextColor != color) && checkerBoard[y+2*modY][x+2*modX] == NULL) {
								moves[i][0] = y+2*modY; 
								moves[i][1] = x+2*modX;
								moves[i][2] = 1;
							}
						}
						break;
					case W:
						modX = -1;
						modY = 0;
						if (checkerBoard[y+modY][x+modX] == NULL) {
							moves[i][0] = y+modY; 
							moves[i][1] = x+modX;
							moves[i][2] = 0;
						} else {
							nextChecker = checkerBoard[y+modY][x+modX];
							nextColor = nextChecker->getColor();
							if ((nextColor != color) && checkerBoard[y+2*modY][x+2*modX] == NULL) {
								moves[i][0] = y+2*modY; 
								moves[i][1] = x+2*modX;
								moves[i][2] = 1;
							}
						}
						break;
					default:
						throw UnknownDirection;
						break; //TODO: Error handling - not a direction.
					}
					i++;
				}
				int j, k;
				int l = 0;
				int movesReturn[24];
				for (j = 0; j < 3; j++) {
					for (k = 0; k < 8; k++) {
							movesReturn[l] = moves[j][k];
							l++;
					}
				}
				return movesReturn;
			}// checkerMoveOptions

			// TODO: Confirm that these operate correctly
			bool MoveChecker(int originX, int originY, int destinationX, int destinationY) {
				bool result = false;
				if(checkerBoard[originY][originX]->getColor() == green && checkerBoard[originY][originX]->Move()){
					result = true;
				}
				checkerBoard[destinationX][destinationY] = checkerBoard[originX][originY];
				checkerBoard[originX][originY] = NULL;
				return result;
			} //MoveChecker

			// TODO: Confirm that these operate correctly
			int* JumpChecker(int originX, int originY, int destinationX, int destinationY) {
				int id;
				int killX = destinationX-((destinationX-originX)/2);
				int killY = destinationY-((destinationY-originY)/2);
				int result[2];

				//Special Checking
				if(checkerBoard[killY][killX]->getColor() == black){
					result[0] = checkerBoard[killY][killX]->GetID();
					if(checkerBoard[killY][killX]->Delete()){
						if(checkerBoard[originY][originX]->getColor() == red && checkerBoard[originY][originX]->IsSpecialAvailable() == true){
							checkerBoard[originX][originY]->UseSpecial();
							result[1] = -1;
						}
						else{
							result[1] = checkerBoard[originY][originX]->GetID();
							checkerBoard[originY][originX] = NULL;
						}
						checkerBoard[killY][killX] = NULL;
					}
				}
				else if(checkerBoard[killY][killX]->getColor() == red){
					if(checkerBoard[killY][killX]->Delete()){
						result[0] = checkerBoard[killY][killX]->GetID();
						result[1] = -1;
						checkerBoard[killY][killX] = NULL;
					}
					else{
						result[0] = -1;
						result[1] = -1;
					}
				}
				else if(checkerBoard[killY][killX]->getColor() == green){
					result[0] = checkerBoard[killY][killX]->GetID();
					result[1] = -1;
					checkerBoard[killY][killX] = NULL;
				}

				checkerBoard[destinationX][destinationY] = checkerBoard[originX][originY];
				checkerBoard[originX][originY] = NULL;

				return result;
			} //JumpChecker
			
			/*Use as reference for now
			bool MoveChecker(int originX, int originY, int destinationX, int destinationY) {
				int jumpX = destinationX-(destinationX-originX);
				int jumpY = destinationY-(destinationY-originY);
				if(checkerBoard[destinationX][destinationY] == NULL){
					checkerBoard[destinationX][destinationY] = checkerBoard[originX][originY];
					checkerBoard[originX][originY] = NULL;
					return true;
				} else if (checkerBoard[destinationX][destinationY]->getColor() != checkerBoard[originX][originY]->getColor()) {
					if (checkerBoard[jumpX][jumpY] == NULL) {
						if (checkerBoard[destinationX][destinationY]->getColor() == red) {
							//Red
							if (checkerBoard[destinationX][destinationY]->isSpecialUsed() == true) {
								checkerBoard[jumpX][jumpY] = checkerBoard[originX][originY];
								checkerBoard[originX][originY] = NULL;
<<<<<<< HEAD
								delChecker(checkerBoard[destinationX][destinationY]->getID);
=======
								delChecker(, checkerBoard[destinationX][destinationY]);
								delChecker(, checkerBoard[destinationX][destinationY]->getID);
>>>>>>> gareth
								checkerBoard[destinationX][destinationY] = NULL;
							} else {
								checkerBoard[destinationX][destinationY]->specialUsed(true);
								checkerBoard[jumpX][jumpY] = checkerBoard[originX][originY];
								checkerBoard[originX][originY] = NULL;
							}
						} else if (checkerBoard[destinationX][destinationY]->getColor() == black) {
							//Black
							if (checkerBoard[destinationX][destinationY]->special() == true) {
								delChecker(checkerBoard[originX][originY]->getID);
								delChecker(checkerBoard[destinationX][destinationY]->getID);
								checkerBoard[originX][originY] = NULL;
							} else {
								checkerBoard[jumpX][jumpY] = checkerBoard[originX][originY];
								delChecker(,checkerBoard[destinationX][destinationY]->getID);
								checkerBoard[destinationX][destinationY] = NULL;
								checkerBoard[originX][originY] = NULL;
							}
						} else {
							checkerBoard[jumpX][jumpY] = checkerBoard[originX][originY];
							delChecker(, checkerBoard[destinationX][destinationY]->getID);
							checkerBoard[destinationX][destinationY] = NULL;
							checkerBoard[originX][originY] = NULL;
						}

						return true;
					}
				} else {
					std::cout << "\nInvalid Move";
					return false;
				}
			} //MoveChecker
			
			
			

			void delChecker(PlayerObj *head, int checkerID) {
<<<<<<< HEAD
=======

>>>>>>> gareth
				CheckerObj *temp;
				CheckerObj *current = head->head;
				if (current->getID == NULL) {
					return;
				} else if (current->getID == checkerID) {
					temp = head->head;
					head->head = head->head->next;
					free(temp);
					return;
				} else {
					temp = current->next;
					while (temp->next != NULL) {
						if (current->getID == checkerID) {	
							current = temp->next;
							free(temp);
						}
						current = temp;
						temp = temp->next;
					}
				}				
			}
			*/
			
			void AddChecker(int destinationX, int destinationY, CheckerObj *checker) {
				checkerBoard[destinationY][destinationX] = checker;
			}


			void AddPlayersCheckers(int xCords[], int yCords[], CheckerObj *ptr){
				int i;
				CheckerObj *temp = ptr;
				for(i = 0; i < 7; i++){
					AddChecker(xCords[i], yCords[i], ptr);


					COORD pos = {0, 30};
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					temp = temp->next;
				}
			}

			void DisplayBoard() {
				// TODO: Update this method to draw each current checker
				guiObj->DisplayBoard();
			} //DisplayBoard

			void DisplayWinner(CheckerObj winner){
				// TODO: Get and display winner color
				char str[50] = "The winner is %s";
				guiObj->DisplayString(0, 20, str);
			}

			void DisplayChecker(){
				int x, y;
				int realX, realY;
				for(x = 0; x < 9; x ++){
					for(y = 0; y < 9; y++){
						realX = 2 + (x * 4);
						realY = 3 + (y * 2);
						COORD pos = {realX , realY};
						
						CheckerObj *currentChecker = checkerBoard[y][x];
						if(!currentChecker){
							continue;
						}
						checkerColor color = currentChecker->getColor();
						bool kinged = currentChecker->IsKinged();
						bool special = currentChecker->IsSpecialAvailable();
						char checkerSymbol[2] = {' ', ' '};

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

						guiObj -> DisplayChar(realX, realY, checkerSymbol[0]);
						guiObj -> DisplayChar((realX + 1), realY, checkerSymbol[1]);
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



		//=============== Private Methods/Members ===============//
		private:
			CheckerObj *checkerBoard[9][9];

			//checkerBoard = new CheckerObj*[9][9];
			//CheckerObj *checkerBoard[9][9];
			GUI_Ascii *guiObj;
			 
	}; //CheckerBoardObj
}