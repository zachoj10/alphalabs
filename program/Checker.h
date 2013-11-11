#pragma once
#include <stdlib.h>
#include <stdio.h>

namespace Checkers {
	class CheckerObj {
		//=============== Public Methods/Members ===============//
		public:
			CheckerObj(int id = 0) {
				checkerID = id;
				specialAbilityAvailable = true;
				kinged = false;
				next = NULL;
			} //__constructor


			bool virtual Move(){
				return false;
			}
			
			
			bool virtual Delete() {
                //TODO:Remove from linked list
				return false;
			}


			void Jump() {
                //TODO
			}


			int GetID() {
				return this->checkerID;
			} //GetID


			checkerColor getColor() {
				return this->color;
			} //GetColor


			void KingMe() {
				int i;
				
				// Allow king to move in all directions
				for (i = 0; i < 8; i++) {
					directions[i] = dArray[i];
				} //for

				this->kinged = true;
			} //KingMe


			bool IsKinged() {
			    return this->kinged;
			} //IsKinged


			bool IsSpecialAvailable() {
			    return this->specialAbilityAvailable;
			} //IsSpecialAvailable


			bool virtual UseSpecial() {
				specialAbilityAvailable = false;
				return specialAbilityAvailable;
			} //SpecialUsed


			checkerDirection getDirection(int i) {
				return this->directions[i];
			}


			CheckerObj *next;
			bool kinged;
			bool specialAbilityAvailable;
			checkerDirection directions[8];
			checkerColor color;

		
		//=============== Protected Methods/Members ===============//
		protected:	
			int checkerID;
	}; //CheckerObj


	class BlackCheckerObj : public CheckerObj	{
		//=============== Public Methods/Members ===============//
		public:
			BlackCheckerObj(int id) : CheckerObj(id) {
				this->color = black;
				this->directions[0] = NE;
				this->directions[1] = NW;
			} //__constructor


			bool UseSpecial() {
				// Call parent method
				CheckerObj::UseSpecial();

				// Give 50% chance to self-destruct
				int boom = rand() % 9;

				if (boom < 5) {
					return true;
				} else {
					return false;
				} //if-else
			} //UseSpecial


			bool Delete() {
				CheckerObj::Delete();
				// Always try to use self-destruct special power

				// Blow up the other checker
				if (UseSpecial()) {
					return true;
				} else {
					// Otherwise, return dummy value and do nothing
					return false;
				} //if-else
			} //Delete
	}; //BlackCheckerObj


	class RedCheckerObj : public CheckerObj {
		//=============== Public Methods/Members ===============//
		public:
			RedCheckerObj(int id) : CheckerObj(id) {
				color = red;
				directions[0] = SE;
				directions[1] = SW;
			} //__constructor


			bool Delete() {
				CheckerObj::Delete();
				if (this->IsSpecialAvailable()) {
					// Always try to use special sheild power if it is available
					this->UseSpecial();
					return false;
				} else {
					// Otherwise, return dummy value and accept our fate...
					return true;
				} //if-else
			} //Delete
	}; //RedCheckerObj


	class GreenCheckerObj : public CheckerObj	{
		//=============== Public Methods/Members ===============//
		public:
			GreenCheckerObj(int id): CheckerObj(id) {
				color = green;
				directions[0] = NW;
				directions[1] = SW;
			} //__constructor


			bool Move() {
				CheckerObj::Move();
				char useSpecial;
				// Prompt user to use special power if it is available
				if (this->IsSpecialAvailable()) {
					do {
						guiObj->DisplayGreenPlayerSpecialMenu();
						useSpecial = guiObj->HandleGreenPlayerSpecialMenuResponse();

						switch (useSpecial) {
							case 'y':
								this->UseSpecial();
								return true;
								break;

							case 'n':
								// Do nothing
								return false;
								break;

							default:
								guiObj->DisplayUserInputError();
							break;
						} //switch
					} while ('n' != useSpecial || 'y' != useSpecial);
				} //if

				// Otherwise, return dummy value and do nothing
				return false;
			} //Move
	}; //GreenCheckerObj
}
