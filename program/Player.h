#pragma once
#include "Checker.h"
#include <stdlib.h>
#include "CheckerBoard.h"


namespace Checkers {
	class PlayerObj {
		public:
			PlayerObj(){
				numCheckers = 0;
				nextID = 0;
			};
			PlayerObj(checkerColor color){
				 numCheckers = 0;
				 pieceColor = color;
				 nextID = 0;
			};
			void killChecker(int id){
				CheckerObj *temp;
				CheckerObj *current = head;
				if (current->getID == NULL) {
					return;
				} else if (current->getID == id) {
					temp = head;
					head = head->next;
					free(temp);
					return;
				} else {
					temp = current->next;
					while (temp->next != NULL) {
						if (current->getID == id) {	
							current = temp->next;
							free(temp);
						}
						current = temp;
						temp = temp->next;
					}
				}
			}

			void generatePieces(){
				int i;
				int newID;
				CheckerObj *temp = head;
				head = createChecker(pieceColor, nextID);
				nextID++;
				for(i = 0; i < 6; i++){
					temp = createChecker(pieceColor, nextID);
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

			CheckerObj* createChecker(checkerColor color, int id, int x, int y) {
				CheckerObj *newChecker;
				switch (color) {
				case black:
					Black *newChecker = new Black(id);
					CheckerBoardObj::DisplayChecker(x, y, newChecker);
					return newChecker;
					break;
				case red:
					Red *newChecker = new Red(id);
					return newChecker;
					break;
				case green:
					Green *newChecker = new Green(id);
					return newChecker;
					break;
				}
			}

			CheckerObj *head;

		private: 
			int numCheckers;
			checkerColor pieceColor;
			int nextID;
	}
}


