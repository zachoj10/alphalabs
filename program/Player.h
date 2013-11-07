#pragma once
#include "Checker.h"
#include <stdlib.h>
#include "CheckerBoard.h"

namespace Checkers{
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
					if(head->next->getID() == id){
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

			CheckerObj* createChecker(checkerColor color, int id) {
				CheckerObj *newChecker;
				if(color == black){
					Black *newChecker = new Black(id);
					return newChecker;
				}
				else if(color == red){
					Red *newChecker = new Red(id);
					return newChecker;
				}
				else if(color == green){
					Green *newChecker = new Green(id);
					return newChecker;
				}
			}

			CheckerObj *head;

		private: 
			int numCheckers;
			checkerColor pieceColor;
			int nextID;
	};


}
