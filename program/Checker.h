#pragma once
#include <stdlib.h>
#include <string.h>

namespace Checkers {
	class CheckerObj {
		public:
			/*void Move(int destinationX, int destinationY, bool isJump)
			{
				currentX = destinationX;
				currentY = destinationY;
				if (isJump) {
					//Do stuff
				}
			}
			void Delete()
			{
                //TODO:Remove from linked list
			}
			void Jump()
			{s
                //TODO
			}*/
			void setID(int id) {
				checkerID = id;
			}
			int getID() {
				return checkerID;
			}
			void kingMe(bool isKing)
			{
				kinged = isKing;
			}
			bool isKinged()
			{
			    return kinged;
			}
			bool isSpecialUsed()
			{
			    return specialAbilityUsed;
			}
			void specialUsed(bool isUsed)
			{
				specialAbilityUsed = isUsed;
			}
			CheckerObj *next;

		private:
			bool kinged;
			bool specialAbilityUsed;
			int checkerID;
			//int currentX;
			//int currentY;
	}; //CheckerObj

	class Black : public CheckerObj
	{
	public:
		Black(int id){
			setID(id);
			specialUsed(false);
			kingMe(false);
		}
			; //constructor
		bool Special() {
			int boom = rand() % 2;
			if (boom == 0) {
				return true;
			} else {
				return false;
			}
		}	
	};

	class Red : public CheckerObj
	{
	public:
		Red(int id){
			setID(id);
			specialUsed(false);
			kingMe(false);
		};
	};

	class Green : public CheckerObj
	{
	public:
		Green(int id){
			setID(id);
			specialUsed(false);
			kingMe(false);
		};
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