#pragma once

// Parent class for GUI functionality
namespace Checkers {
	class GUI {
		public:
			GUI(void);
			~GUI(void);
			void DisplayBoard();
			void DisplayMenu();
	};
}