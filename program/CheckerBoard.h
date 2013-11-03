#pragma once
#include "Checker.h"
#include "GUI_Ascii.h"
#include "Player.h"

namespace Checkers {
	class CheckerBoardObj {
		//=============== Public Methods/Members ===============//
		public: 
			typedef enum {black, red, green} checkerColor;

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
							if (checkerBoard[destinationX][destinationY]->isSpecialUsed() == true) {
								checkerBoard[jumpX][jumpY] = checkerBoard[originX][originY];
								checkerBoard[originX][originY] = NULL;
								delChecker(checkerBoard[destinationX][destinationY]);
								checkerBoard[destinationX][destinationY] = NULL;
							} else {
								checkerBoard[destinationX][destinationY]->specialUsed(true);
								checkerBoard[jumpX][jumpY] = checkerBoard[originX][originY];
								checkerBoard[originX][originY] = NULL;
							}
						} else if (checkerBoard[destinationX][destinationY]->getColor() == black) {
							if (checkerBoard[destinationX][destinationY]->special() == true) {
								delChecker(checkerBoard[originX][originY]);
								delChecker(checkerBoard[destinationX][destinationY]);
								checkerBoard[originX][originY] = NULL;
							} else {
								checkerBoard[jumpX][jumpY] = checkerBoard[originX][originY];
								delChecker(checkerBoard[destinationX][destinationY]);
								checkerBoard[destinationX][destinationY] = NULL;
								checkerBoard[originX][originY] = NULL;
							}
						} else {
							checkerBoard[jumpX][jumpY] = checkerBoard[originX][originY];
							delChecker(checkerBoard[destinationX][destinationY]);
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
			
			void delChecker(Players::PlayerObj *first, Checkers::CheckerObj *checker) {
				int i;
				Players::PlayerObj *temp = first;
				if (temp->getHead->getID == checker->getID) {
					//delete NODE
				} else if (temp->getHead->next->getID == checker->getID) {
					temp = temp->getHead->next;
					first->getHead = temp->getHead->next->next;
					free(temp);
				} else {
					for(i = 0; i < 7; i++){
						temp = temp->next;
						//Incomplete					
							
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

			void DisplayChecker(int x, int y, Checkers::CheckerObj checker){
				COORD pos = {x , y};
				Checkers::checkerColor color = checker.getColor();
				char checkerSymbol;
				if(color == black){
					checkerSymbol  = 'B';
				}
				else if(color == green){
					checkerSymbol = 'G';
				}
				else {
					checkerSymbol = 'R';
				}

				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

				printf("%c", checker);
			}



		//=============== Private Methods/Members ===============//
		private:
			Checkers::CheckerObj *checkerBoard[9][9];
			GUI_Ascii *guiObj;
			 
	}; //CheckerBoardObj
}