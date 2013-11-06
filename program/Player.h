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

			void setNumCheckers(int num){
				numCheckers = num;
			}

			int getNumCheckers(){
				return numCheckers;
			}

			Checkers::CheckerObj* getHead(){
				return head;
			}

			Checkers::CheckerObj* createChecker(Checkers::checkerColor color, int id, int x, int y) {
				Checkers::CheckerObj *newChecker;
				switch (color) {
				case Checkers::black:
					Checkers::Black *newChecker = new Checkers::Black(id);
					Checkers::CheckerBoardObj::DisplayChecker(x, y, newChecker);
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

			Checkers::CheckerObj *head;

		private: 
			int numCheckers;
			Checkers::checkerColor pieceColor;
			int nextID;
	}
}


