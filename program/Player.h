#pragma once
#include "Checker.h"
#include <stdlib.h>


namespace Players {
	class PlayerObj {
		public:
			PlayerObj(enum checkerColors color, Checkers::CheckerObj *first){
				 numCheckers = 0;
				 pieceColor = color;
				 head = first;
				 highestID = 0;
			};
			void Delete(int id){
				Checkers::CheckerObj *temp = NULL;
				int i;
				for(i = 0; i < numCheckers; i++){
					if(head->next.getID() == id){
						temp = head->next;
						head->next = head->next->next;
						free(temp);
					}
				}
			}
			void generatePieces(){
				int i;
				int newID;
				Checkers::CheckerObj *temp = head;
				head = Checkers::createChecker(pieceColor, nextID);
				nextID++;
				for(i = 0; i < 6; i++){
					temp = Checkers::createChecker(pieceColor, nextID);
					temp->next = head;
					head = temp;
					nextID++;
				}
			}

		private: 
			int numCheckers;
			checkerColors pieceColor;
			Checkers::CheckerObj *head;
			int nextID;
	};
}