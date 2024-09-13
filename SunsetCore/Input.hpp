#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Point.hpp"

namespace SunsetEngine
{
	class Button
	{
	private:
		std::string name;
		char bound_character;
		bool was_button_pressed;
	public:
		Button(std::string name, char bound_character):
		name(name), bound_character(bound_character)
		{
			std::cout << name << " bound to [ " << bound_character << " ]\n";
		}
		//Wrap for input library.
		void update();
		void setPressedState(bool press_state){ was_button_pressed = press_state; }
		bool wasPressed(){ return was_button_pressed; }
		char getBinding(){ return bound_character; }
	};

	class ButtonList
	{
	private:
		std::vector<Button> buttons;
	public:
		Button getButton(int i);
		void addButton(Button new_button)
		{
			buttons.push_back(new_button);
		}
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