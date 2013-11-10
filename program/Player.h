#pragma once
#include <stdlib.h>
#include "Checker.h"
#include "CheckerBoard.h"

namespace Checkers {
	//static int nextID = 0;
	class PlayerObj {
		
		//=============== Public Methods/Members ===============//
		public:
			PlayerObj() {
				numCheckers = 0;
				active = false;
			};


			PlayerObj(checkerColor color) {
				 numCheckers = 0;
				 pieceColor = color;
				 active = true;
				 generatePieces();
			};  //__constructor


			~PlayerObj() {
				// Delete all checkers in a player's linked list
				CheckerObj *current = head;

				while (current != 0) {
					CheckerObj* next = current->next;
					delete current;
					current = next;
				} //while

				head = NULL;
			} //__destructor


			void KillChecker(int id) {
				CheckerObj *temp;
				CheckerObj *current = head;
				if (current == NULL) {
					return;
				} else if (current != NULL && current->GetID() == id) {
					temp = head;
					head = head->next;
					free(temp);
					return;
				} else {
					temp = current->next;
					while (temp->next != NULL) {
						int nextID = temp->GetID();
						if (nextID == id) {	
							current->next = current->next->next;
							free(temp);
							break;
						} //if

						current = temp;
						temp = temp->next;
					} //while
				} //if-elseif-else
			} //KillChecker

			void generatePieces(){
				try {
					int i;
					CheckerObj *temp = head;
				
					head = CreateChecker();
					//nextID++;
					for(i = 0; i < 7; i++){
						temp = CreateChecker();
						temp->next = head;
						head = temp;
						//nextID++;
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


			static int getNextID(){
				int result;
				static int nextID = 0;
				result = nextID;
				nextID++;
				return result;
			}

			int getNumCheckers(){
				return numCheckers;
			}

			CheckerObj* GetHead(){
				return head;
			}

			CheckerObj* CreateChecker() {
				switch (pieceColor) {
					case black:
						return new BlackCheckerObj(getNextID());
						break;
					case red:
						return new RedCheckerObj(getNextID());
						break;
					case green:
						return new GreenCheckerObj(getNextID());	
						break;
					default:
						throw UnknownColor;
						break;
				} //switch
			} //CreateChecker


			void AddPieceToList(){
				
				CheckerObj *temp = head;
				//nextID++;

				temp = CreateChecker();
				temp->next = head;
				head = temp;
			}

			checkerColor getColor(){
				return pieceColor;
			}

			bool getActive(){
				return active;
			}


			CheckerObj *head;
			bool active;

		//=============== Private Methods/Members ===============//
		private: 
			int numCheckers;
			checkerColor pieceColor;
	}; //PlayerObj
}

/*
The IDs are not unique for each color. Do we want to develop a new ID system to uniquely identify a piece by checking only one condition?
	The way we have it set up we need to use two conditions to identify a checker (i.e. Red 1) 
*/