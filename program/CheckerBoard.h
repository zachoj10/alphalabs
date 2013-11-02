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
			
			
			void createChecker(checkerColors color, int id) {
				switch (color) {
				case black:
					Black *newChecker = new Black(id);
					break;
				case red:
					Red *newChecker = new Red(id);
					break;
				case green:
					Green *newChecker = new Green(id);
					break;
			}

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

			void DisplayWinner(CheckerObj winner){
				std::cout << "The winner is %s", typeid(winner).name();
			}



		//=============== Private Methods/Members ===============//
		private:
			CheckerObj *checkerBoard[9][9];
			GUI_Ascii *guiObj;
			 
	}; //CheckerBoardObj
}