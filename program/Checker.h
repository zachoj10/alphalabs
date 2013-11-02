#pragma once
#include <stdlib.h>
#include <stdio.h>

namespace Checkers {
	class CheckerObj {
<<<<<<< HEAD
			typedef enum {black, red, green} checkerColors;

	
			void Move(int destinationX, int destinationY, bool isJump)
=======
		public:
			typedef enum {black, red, green} checkerColor;
			/*void Move(int destinationX, int destinationY, bool isJump)
>>>>>>> gareth
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
<<<<<<< HEAD
			}

			
			void setID(int id) {
				checkerID = id;
=======
			}*/

			void createChecker(checkerColor color, int id) {
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
			}
			void setID(int checkerID) {
				this->checkerID = checkerID;
>>>>>>> gareth
			}
			int getID() {
				return this->checkerID;
			}
			checkerColor getColor() {
				return this->color 
			}
			void setColor(checkerColor color) {
				this->color = color;
			}
			void kingMe(bool kinged)
			{
				this->kinged = kinged;
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
			CheckerObj *next;

		private:
			bool kinged;
			bool specialAbilityUsed;
			int checkerID;
<<<<<<< HEAD
			int currentX;
			int currentY;
=======
			checkerColor color;
			//int currentX;
			//int currentY;
>>>>>>> gareth
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
			this->setColor(black);
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
			this->setColor(red);
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
			this->setColor(green);
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
