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
<<<<<<< HEAD
			};
=======
			}
>>>>>>> gareth
			void Delete(int id){
				Checkers::CheckerObj *temp = NULL;
				int i;
				for(i = 0; i < numCheckers; i++){
<<<<<<< HEAD
					if(head->next.getID() == id){
=======
					if(head->next->getID == id){
>>>>>>> gareth
						temp = head->next;
						head->next = head->next->next;
						free(temp);
					}
				}
			}
<<<<<<< HEAD
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
=======
>>>>>>> gareth

		private: 
			int numCheckers;
			checkerColors pieceColor;
			Checkers::CheckerObj *head;
<<<<<<< HEAD
			int nextID;
	};
=======
			int highestID;
	}
>>>>>>> gareth
}