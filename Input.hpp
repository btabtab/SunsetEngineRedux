#pragma once

#include <complex>
#include "Point.hpp"

namespace SunsetEngine
{
	class Button
	{
	private:
		char button_label;
		bool was_button_pressed;
	public:
		//Wrap for input library.
		void update();
		bool wasPressed(){ return was_button_pressed; }
	};

	class Cursor
	{
		//Where the cursor is.
		Point position;
		//Was the left button pressed.
		bool left;
		//Was the right button pressed.
		bool right;

	public:
		/*
			Updates the cursor, what
			more could this mean?
		*/
		void update();
	};
};