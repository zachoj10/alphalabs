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
			void Delete(int id){
				CheckerObj *temp = NULL;
				int i;
				for(i = 0; i < numCheckers; i++){
					if(head->next->getID == id){
						temp = head->next;
						head->next = head->next->next;
						free(temp);
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


