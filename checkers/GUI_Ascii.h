#pragma once

namespace Checkers {
	class GUI_Ascii {
		//=============== Public Methods/Members ===============//
		public:
			void DisplayBoard() {
				// TODO: Add display for checker board
			} //DisplayBoard


			void DisplayMenu() {
				printf("\nMenu Options\n");
				printf("------------------------------------------------------\n");
				printf("p: Play\n");
				printf("q: Quit\n");

				printf("\n\nPlease enter a choice ---> ");
			} //DisplayMenu
	}; //GUI_Ascii
}