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
		bool wasPressed(){ return was_button_pressed; }
		char getBinding(){ return bound_character; }
	};

	class ButtonList
	{
	private:
		std::vector<Button> buttons;
	public:
		Button getButton(int i){ return buttons.at(i); }
		void addButton(Button new_button)
		{
			buttons.push_back(new_button);
		}
		void updateButtons()
		{
			for(int i = 0; i != buttons.size(); i++)
			{
				buttons.at(i).update();
			}
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
		Cursor():
		position(Point(0, 0)), left(false), right(false)
		{
		}
		bool getLeftState(){ return left; }
		bool getRightState(){ return right; }
		/*
			Updates the cursor, what
			more could this mean?
		*/
		void update();

		Point getPosition(){ return position; }
	};
};