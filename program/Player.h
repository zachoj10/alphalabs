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

				if (current->GetID() == NULL) {
					return;
				} else if (current->GetID() == id) {
					temp = head;
					head = head->next;
					free(temp);
					return;
				} else {
					temp = current->next;
					while (temp->next != NULL) {
						if (current->GetID() == id) {	
							current = temp->next;
							free(temp);
						} //if

						current = temp;
						temp = temp->next;
					} //while
				} //if-elseif-else
			} //KillChecker

			void generatePieces(){
				try {
					int i;
					int newID;
					CheckerObj *temp = head;
				
					head = CreateChecker();
					nextID++;
					for(i = 0; i < 7; i++){
						temp = CreateChecker();
						temp->next = head;
						head = temp;
						nextID++;
						numCheckers++;
					}//for
				} catch (int e) {
					if (e == UnknownColor) {
						std::cerr<<"Unknown Color Error";	
					}//if
				}//try-catch
			}//GeneratePieces

			void SetNumCheckers(int num){
				numCheckers = num;
			}

			int GetNumCheckers(){
				return numCheckers;
			}

			CheckerObj* GetHead(){
				return head;
			}

			CheckerObj* CreateChecker() {
				switch (pieceColor) {
					case black:
						return new BlackCheckerObj(nextID);
						break;
					case red:
						return new RedCheckerObj(nextID);
						break;
					case green:
						return new GreenCheckerObj(nextID);	
						break;
					default:
						throw UnknownColor;
						break;
				} //switch
			} //CreateChecker

			checkerColor GetColor(){
				return pieceColor;
			}


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