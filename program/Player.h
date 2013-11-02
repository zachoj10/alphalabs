#pragma once
#include "Checker.h"
#include <stdlib.h>


namespace Players {
	class PlayerObj {
		public:
			PlayerObj(Checkers::checkerColor color, Checkers::CheckerObj *first){
				 numCheckers = 0;
				 pieceColor = color;
				 head = first;
				 nextID = 0;
			}
			void Delete(int id){
				Checkers::CheckerObj *temp = NULL;
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
				Checkers::CheckerObj *temp = head;
				head = createChecker(pieceColor, nextID);
				nextID++;
				for(i = 0; i < 6; i++){
					temp = createChecker(pieceColor, nextID);
					temp->next = head;
					head = temp;
					nextID++;
				}
			}

			Checkers::CheckerObj* createChecker(Checkers::checkerColor color, int id) {
				Checkers::CheckerObj *newChecker;
				switch (color) {
				case Checkers::black:
					Checkers::Black *newChecker = new Checkers::Black(id);
					return newChecker;
					break;
				case Checkers::red:
					Checkers::Red *newChecker = new Checkers::Red(id);
					return newChecker;
					break;
				case Checkers::green:
					Checkers::Green *newChecker = new Checkers::Green(id);
					return newChecker;
					break;
				}
			}
		private: 
			int numCheckers;
			Checkers::checkerColor pieceColor;
			Checkers::CheckerObj *head;
			int nextID;
	}
}


