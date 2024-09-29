#pragma once

#include "RenderObject.hpp"
#include "Colour.hpp"
#include "../Point.hpp"
#include "../Line.hpp"

namespace SunsetEngine
{
	//Derives from Line and RenderObject
	class RenderLine : public Line, public RenderObject
	{
	private:
		Colour colour;
	public:
		RenderLine(Colour colour, int new_ID):
        Line(Line(0, 0, 0, 0)), colour(colour)
        {
			ID = new_ID;
        }
		RenderLine(Point a, Point b, Colour colour, int new_ID):
        colour(colour)
        {
            this->a = a;
            this->b = b;
			ID = new_ID;
        }
		void render();
	};
};