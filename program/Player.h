#pragma once
#include <stdlib.h>
#include "Checker.h"
#include "CheckerBoard.h"

namespace Checkers {
	class PlayerObj {
		//=============== Public Methods/Members ===============//
		public:
			PlayerObj(){
				numCheckers = 0;
				nextID = 0;
			};


			PlayerObj(checkerColor color) {
				 numCheckers = 0;
				 pieceColor = color;
				 nextID = 0;
				 generatePieces();
			};  //__constructor


			~PlayerObj() {
				// TODO: Add memory freeing commands
			} //__destructor


			void KillChecker(int id) {
				CheckerObj *temp;
				CheckerObj *current = head;

				if (current->getID() == NULL) {
					return;
				} else if (current->getID() == id) {
					temp = head;
					head = head->next;
					free(temp);
					return;
				} else {
					temp = current->next;
					while (temp->next != NULL) {
						if (current->getID() == id) {	
							current = temp->next;
							free(temp);
						} //if

						current = temp;
						temp = temp->next;
					} //while
				} //if-elseif-else
			} //KillChecker

			void generatePieces(){
				int i;
				int newID;
				CheckerObj *temp = head;
				head = CreateChecker();
				nextID++;
				for(i = 0; i < 6; i++){
					temp = CreateChecker();
					temp->next = head;
					head = temp;
					nextID++;
				}
			}

			void setNumCheckers(int num){
				numCheckers = num;
			}

			int getNumCheckers(){
				return numCheckers;
			}

			CheckerObj* getHead(){
				return head;
			}

			CheckerObj* CreateChecker() {
				switch (pieceColor) {
				case black:
					return new Black(nextID);
					break;
				case red:
					return new Red(nextID);
					break;
				case green:
					return new Green(nextID);	
					break;
				default:
					//TODO: Handle this default case somehow; possible with an exception handler 
					break;
				}
			} //CreateChecker


			CheckerObj *head;

		//=============== Private Methods/Members ===============//
		private: 
			int numCheckers;
			checkerColor pieceColor;
			int nextID;
	}; //PlayerObj
}

/*
The IDs are not unique for each color. Do we want to develop a new ID system to uniquely identify a piece by checking only one condition?
	The way we have it set up we need to use two conditions to identify a checker (i.e. Red 1) 
*/