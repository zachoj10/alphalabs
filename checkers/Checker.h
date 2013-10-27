#pragma once

namespace Checkers {
	class CheckerObj {
		public:
			void Move(int destinationX, int destinationY);
			void Delete();
			void Jump();
			void KingMe();

		private:
			bool isKinged;
			bool specialAbilityUsed;
	}; //CheckerObj
}