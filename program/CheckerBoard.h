#pragma once
#include "Checker.h"
#include "GUI_Ascii.h"
#include "Player.h"

namespace Checkers{
	class CheckerBoardObj {
		//=============== Public Methods/Members ===============//
		public: 
			CheckerBoardObj(PlayerObj playerList[]) {
				// TODO: Add constructor that specifies between 2 players (black vs red) and 3 players (black vs red vs green)
				
				// Instantiate class objects
				guiObj = new GUI_Ascii();
			} //__constructor


			// TODO: Confirm that these operate correctly
			void MoveChecker(int originX, int originY, int destinationX, int destinationY) {
				int jumpX = destinationX-(destinationX-originX);
				int jumpY = destinationY-(destinationY-originY);

				checkerBoard[destinationX][destinationY] = checkerBoard[originX][originY];
				checkerBoard[originX][originY] = NULL;
			} //MoveChecker

			// TODO: Confirm that these operate correctly
			int JumpChecker(int originX, int originY, int destinationX, int destinationY) {
				int id;
				int jumpX = destinationX-(destinationX-originX);
				int jumpY = destinationY-(destinationY-originY);

				checkerBoard[destinationX][destinationY] = checkerBoard[originX][originY];
				id = checkerBoard[jumpX][jumpY].getID();
				checkerBoard[originX][originY] = NULL;

				return id;
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
			
			void AddChecker(int destinationX, int destinationY, CheckerObj checker) {
				checkerBoard[destinationX][destinationY] = checker;
			}


			void AddPlayersCheckers(int xCords[], int yCords[], CheckerObj *ptr){
				int i;
				CheckerObj *temp = ptr;
				for(i = 0; i < 7; i++){
					AddChecker(xCords[i], yCords[i], *temp);
					COORD pos = {0, 30};
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					//std::cout << xCords[i];
					//std::cout << yCords[i];
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
						CheckerObj currentChecker = checkerBoard[x][y];
						checkerColor color = currentChecker.getColor();
						bool kinged = currentChecker.isKinged();
						char checkerSymbol[2] = {' ', ' '};
						if(color == black){
							checkerSymbol[0]  = 'B';
						}
						else if(color == green){
							checkerSymbol[0] = 'G';
						}
						else if(color == red){
							checkerSymbol[0] = 'R';
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



		//=============== Private Methods/Members ===============//
		private:
			CheckerObj checkerBoard[9][9];
			GUI_Ascii *guiObj;
			 
	}; //CheckerBoardObj
}