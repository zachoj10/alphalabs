#pragma once
#include "Checker.h"
#include "GUI_Ascii.h"

namespace Checkers {
	class CheckerBoardObj {
		//=============== Public Methods/Members ===============//
		public: 
			CheckerBoardObj(CheckerObj playerList[]) {
				// TODO: Add constructor that specifies between 2 players (black vs red) and 3 players (black vs red vs green)
				
				// Instantiate class objects
				this->guiObj = new GUI_Ascii();
			} // __constructor
			
			bool MoveChecker(int originX, int originY, int destinationX, int destinationY) {
				int jumpX = destinationX+(destinationX-originX);
				int jumpY = destinationY+(destinationY-originY);
				if(checkerBoard[destinationX][destinationY] == NULL){
					checkerBoard[destinationX][destinationY] = checkerBoard[originX][originY];
					checkerBoard[originX][originY] = NULL;
					return true;
				} else if (checkerBoard[destinationX][destinationY]->getColor != checkerBoard[originX][originY]->getColor) {
					if (checkerBoard[jumpX][jumpY] == NULL) {
						checkerBoard[jumpX][jumpY] = checkerBoard[originX][originY];
						checkerBoard[originX][originY] = NULL;
						return true;
					}
				} else {
					std::cout << "\nInvalid Move";
					return false;
				}
			} //MoveChecker
			/* Moving to player class
			void AddChecker(int destinationX, int destinationY) {
				CheckerObj *newChecker = new CheckerObj();
				checkerBoard[destinationX][destinationY] = newChecker;
			} //AddChecker


			void DeleteChecker(int originX, int originY) {
				checkerBoard[originX][originY]->Delete();
			} //RemoveChecker
			*/

			void DisplayBoard() {
				// TODO: Update this method to draw each current checker
				guiObj->DisplayBoard();
			} //DisplayBoard


		//=============== Private Methods/Members ===============//
		private:
			CheckerObj *checkerBoard[9][9];
			GUI_Ascii *guiObj;
			 
	}; //CheckerBoardObj
}