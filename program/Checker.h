#pragma once
#include <stdlib.h>
#include <stdio.h>

namespace Checkers {
	class CheckerObj {
			typedef enum {black, red, green} checkerColors;

	
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
                //TODO:Remove from linked list
			}
			void Jump(){
                //TODO
			}

			
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
			int currentX;
			int currentY;
	}; //CheckerObj

	class Black : public CheckerObj
	{
	public:
		Black(int id){
			setID(id);
			specialUsed(false);
			kingMe(false);
			this->setID(id);
			this->specialUsed(false);
			this->kingMe(false);
		}
			; //constructor
		bool special() {
			int boom = rand() % 2;
			if (boom == 0) {
				this->specialUsed(true);
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
			this->setID(id);
			this->specialUsed(false);
			this->kingMe(false);
		};
	};

	class Green : public CheckerObj
	{
	public:
		Green(int id){
			setID(id);
			specialUsed(false);
			kingMe(false);
		}
		bool special() {
			if (isSpecialUsed() != true) {
			this->setID(id);
			this->specialUsed(false);
			this->kingMe(false);
		}
		bool special() {
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
						this->specialUsed(true);
						return true;
					} else if (use == 'n') {
						this->specialUsed(false);
						return false;
					} else {
						std::cout << "\nEnter only y or n";
					}				
				} while (use != 'y' && use != 'n');
			}
		};
	};

}
