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


			void MoveChecker(int originX, int originY, int destinationX, int destinationY) {
				boolean isJump = false;
				if(checkerBoard[destinationX][destinationY] != NULL){
					isJump = true;
				}
				checkerBoard[originX][originY]->Move(destinationX, destinationY, isJump);
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