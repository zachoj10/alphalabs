#pragma once
#include "Checker.h"
#include "GUI_Ascii.h"

namespace Checkers {
	class CheckerBoardObj {
		//=============== Public Methods/Members ===============//
		public: 
			typedef enum {black, red, green} checkerColors;
			CheckerBoardObj(CheckerObj playerList[]) {
				// TODO: Add constructor that specifies between 2 players (black vs red) and 3 players (black vs red vs green)
				
				// Instantiate class objects
				this->guiObj = new GUI_Ascii();
			} // __constructor


			void MoveChecker(int originX, int originY, int destinationX, int destinationY) {
				boolean isJump = false;
				if(checkerBoard[destinationX][destinationY] != NULL){
					isJump = true;
				}
				checkerBoard[originX][originY]->Move(destinationX, destinationY, isJump);
			} //MoveChecker
			
			

			
			void AddChecker(int destinationX, int destinationY, Checkers::CheckerObj *checker) {
				checkerBoard[destinationX][destinationY] = checker;
			} //AddChecker

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
				checkerColor color = checker.getColor();
				char checkerSymbol;
				if(color == "Black"){
					checkerSymbol  = 'B';
				}
				else if(color == "Green"){
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
			CheckerObj *checkerBoard[9][9];
			GUI_Ascii *guiObj;
			 
	}; //CheckerBoardObj
}