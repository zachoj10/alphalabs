#pragma once
#include <stdlib.h>

namespace Checkers {
	class CheckerObj {
		public:
			void Move(int destinationX, int destinationY, bool isJump)
			{
				currentX = destinationX;
				currentY = destinationY;
				if (isJump) {
					//Do stuff
				}
			}
			void Delete()
			{
                //TODO:Remove from board and/or linked list
			}
			void Jump()
			{
                //TODO
			}
			void KingMe()
			{
				kinged = true;
			}
			bool isKinged()
			{
			    return kinged;
			}
			bool isSpecialUsed()
			{
			    return specialAbilityUsed;
			}
			void specialUsed()
			{
				specialAbilityUsed = true;
			}
			CheckerObj *next;

		private:
			bool kinged;
			bool specialAbilityUsed;
			int currentX;
			int currentY;
	}; //CheckerObj

	class Black : public CheckerObj
	{
	public:
		bool Special() {
			int boom = rand() % 10 + 1;
			if (boom > 5) {
				return true;
			} else {
				return false;
			}
		}	
	};

}
/*Questions:
-How are we generating the checkers and placing them on the board. 
	Black* blackChecker = new Black[7];
		Creates an array of black checkers which can be referred to by blackChecker[0]
		Can be displayed on board as B0, B1, B2, etc. "B" + 
-It seems that the logic for movement should be handled in the game driver, using the move() function to set the new location and
	applying that to the game board.

*/