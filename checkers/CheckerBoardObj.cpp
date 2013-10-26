#include "CheckerBoardHeader.h"

namespace Checkers {
	class CheckerBoardObj {
		//=============== Public Methods/Members ===============//
		public: 
			CheckerBoardObj(int numberOfPlayers) {
				// TODO: Add constructor that specifies between 2 players (black vs red) and 3 players (black vs red vs green)
			} // __constructor


			void MoveChecker(int originX, int originY, int destinationX, int destinationY) {
				checkerBoard[originX][originY]->Move(destinationX, destinationY);
			} //MoveChecker
			
			
			void AddChecker(int destinationX, int destinationY) {
				CheckerObj *newChecker = new CheckerObj();
				checkerBoard[destinationX][destinationY] = newChecker;
			} //AddChecker


			void DeleteChecker(int originX, int originY) {
				checkerBoard[originX][originY]->Delete;
			} //RemoveChecker


		//=============== Private Methods/Members ===============//
		private: 
			CheckerObj* checkerBoard[9][9];
	}; //CheckerBoardObj
}