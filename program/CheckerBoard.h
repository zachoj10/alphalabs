#pragma once
#include "Checker.h"
#include "GUI_Ascii.h"
#include "Player.h"

namespace Checkers {
	class CheckerBoardObj {
		//=============== Public Methods/Members ===============//
		public: 

			CheckerBoardObj(CheckerObj playerList[]) {
				// TODO: Add constructor that specifies between 2 players (black vs red) and 3 players (black vs red vs green)
				
				// Instantiate class objects
				guiObj = new GUI_Ascii();
			} // __constructor
			
			bool MoveChecker(int originX, int originY, int destinationX, int destinationY) {
				int jumpX = destinationX+(destinationX-originX);
				int jumpY = destinationY+(destinationY-originY);
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
								delChecker(, checkerBoard[destinationX][destinationY]->getID);
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
			
			void delChecker(Players::PlayerObj *head, int checkerID) {
				Checkers::CheckerObj *temp;
				Checkers::CheckerObj *current = head->head;
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

			
			void AddChecker(int destinationX, int destinationY, Checkers::CheckerObj *checker) {
				checkerBoard[destinationX][destinationY] = checker;
			}


			void AddPlayersCheckers(int xCords[], int yCords[], Checkers::CheckerObj *ptr){
				int i;
				Checkers::CheckerObj *temp = ptr;
				for(i = 0; i < 7; i++){
					AddChecker(xCords[i], yCords[i], temp);
					temp = temp->next;
				}
			}

			/*
			void DeleteChecker(int originX, int originY) {
				checkerBoard[originX][originY]->Delete();
			} //RemoveChecker
			*/

			void DisplayBoard() {
				// TODO: Update this method to draw each current checker
				guiObj->DisplayBoard();
			} //DisplayBoard

			void DisplayWinner(CheckerObj winner){
				std::cout << "The winner is %s", typeid(winner).name();
			}

			void DisplayChecker(){
				int x, y;
				int realX, realY;
				for(x = 0; x < 9; x ++){
					for(y = 0; y < 9; y++){
						realX = 2 + 3*x;
						realY = 3 + 3*x;
						COORD pos = {realX , realY};
						Checkers:CheckerObj currentChecker = checkerBoard[x][y];
						Checkers::checkerColor color = currentChecker.getColor();
						bool kinged = currentChecker.isKinged();
						char checkerSymbol[3] = "  ";
						if(color == black){
							checkerSymbol[0]  = 'B';
						}
						else if(color == green){
							checkerSymbol[0] = 'G';
						}
						else if(color == red){
							checkerSymbol[0] = 'R';
						}
						if(kinged == true){
							checkerSymbol[1] = 'K';
						}
						else {
							checkerSymbol[1] = ' ';
						}

						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

						printf("%c", checkerSymbol);
					}
				}
			}



		//=============== Private Methods/Members ===============//
		private:
			Checkers::CheckerObj *checkerBoard[9][9];
			GUI_Ascii *guiObj;
			 
	}; //CheckerBoardObj
}