#include "CheckerHeader.h"

namespace Checkers {
	class CheckerBoardObj {
		public:
			CheckerBoardObj(int numberOfPlayers);
			void MoveChecker(int originX, int originY, int destinationX, int destinationY);
			void AddChecker(int destinationX, int destinationY);
			void DeleteChecker(int originX, int originY);

		private: 
			CheckerObj* checkerBoard[9][9];
	}; //CheckerBoardObj
}