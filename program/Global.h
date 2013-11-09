#pragma once
#include "GUI_Ascii.h"

namespace Checkers {
	enum checkerColor {black, red, green, NUM_OF_COLORS};
	enum checkerDirection {SE, SW, NE, NW, N, S, E, W, NUM_OF_DIRECTIONS};
	checkerDirection dArray[8] = {SE, SW, NE, NW, N, S, E, W};
	GUI_Ascii *guiObj = new GUI_Ascii();
}