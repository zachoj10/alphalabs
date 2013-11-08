#pragma once
#include "Checker.h"
#include <stdlib.h>
#include "CheckerBoard.h"

namespace Checkers{
	class PlayerObj {
		public:
			typedef enum {black, red, green} checkerColor;
			typedef enum {SE, SW, NE, NW, N, S, E, W} checkerDirection;
			PlayerObj(){
				numCheckers = 0;
				nextID = 0;
			};
			PlayerObj(checkerColor color){
				 numCheckers = 0;
				 pieceColor = color;
				 nextID = 0;
				 generatePieces();
			};

			void killChecker(int id){
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
				head = createChecker();
				nextID++;
				for(i = 0; i < 6; i++){
					temp = createChecker();
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

			CheckerObj* createChecker() {
				if(pieceColor == black){
					return new Black(nextID);
				}
				else if(pieceColor == red){
					return new Red(nextID);
				}
				else if(pieceColor == green){
					return new Green(nextID);	
				}
			}
			CheckerObj *head;

		private: 
			int numCheckers;
			checkerColor pieceColor;
			int nextID;
	};


}

/*
The IDs are not unique for each color. Do we want to develop a new ID system to uniquely identify a piece by checking only one condition?
	The way we have it set up we need to use two conditions to identify a checker (i.e. Red 1) 
*/