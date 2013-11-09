#pragma once
#include <stdlib.h>
#include <stdio.h>

namespace Checkers {
	class CheckerObj {
		public:
			CheckerObj(){}
			CheckerObj(int id){
				checkerID = id;
				specialAbilityUsed = false;
				kinged = false;
			}

			bool special();
			
			void Move(int destinationX, int destinationY, bool isJump) {
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
			void Jump(){
                //TODO
			}

			void setID(int checkerID) {
				this->checkerID = checkerID;

			}
			int getID() {
				return this->checkerID;
			}
			checkerColor getColor() {
				return color;
			}
			void setColor(checkerColor color) {
				this->color = color;
			}
			void kingMe()
			{
				int i;
				for (i = 0; i < 8; i++) {
					directions[i] = dArray[i];
				}
				this->kinged = true;
			}
			bool isKinged()
			{
			    return this->kinged;
			}
			bool isSpecialUsed()
			{
			    return this->specialAbilityUsed;
			}
			void specialUsed(bool isUsed)
			{
				specialAbilityUsed = isUsed;
			}

			checkerDirection getDirection(int i) {
				return this->directions[i];
			}

			CheckerObj *next;
			bool kinged;
			bool specialAbilityUsed;
			checkerDirection directions[8];
			checkerColor color;
		private:
			
			int checkerID;
			int currentX;
			int currentY;
			

	}; //CheckerObj

	class Black : public CheckerObj
	{
	public:
		Black(int id) : CheckerObj(id) {
			color = black;
			directions[0] = NE;
			directions[1] = NW;
		} //constructor
		
		bool Black::special() {
			int boom = rand() % 2;
			if (boom == 0) {
				this->specialUsed(true);
				return true;
			} else {
				return false;
			}
		}
	private:
		using CheckerObj::special;
		using CheckerObj::directions;
		using CheckerObj::kinged;
		using CheckerObj::specialAbilityUsed;

	};

	class Red : public CheckerObj
	{
	public:
		Red(int id) : CheckerObj(id) {
			color = red;
			directions[0] = SE;
			directions[1] = SW;
		};
	private:
		using CheckerObj::special;
		using CheckerObj::directions;
		using CheckerObj::kinged;
		using CheckerObj::specialAbilityUsed;
	};


	class Green : public CheckerObj
	{
	public:
		Green(int id): CheckerObj(id){
			color = green;
			directions[0] = NW;
			directions[1] = SW;
		}
		bool Green::special() {
			if (this->isSpecialUsed() == false) {
				char use;
				do {
					std::cout << "\nDo you want to use your special? (y/n)";
					std::cin >> use;
					if (use == 'y') {
						specialUsed(true);
						return true;
					} else if (use == 'n') {
						return false;
					} else {
						std::cout << "\nEnter only y or n";
					}
				} while (use != 'y' && use != 'n');
			}
		}
	private:
		using CheckerObj::special;
		using CheckerObj::directions;
		using CheckerObj::kinged;
		using CheckerObj::specialAbilityUsed;
	};

}
