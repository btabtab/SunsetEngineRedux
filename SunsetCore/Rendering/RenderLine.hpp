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
		RenderLine(Colour colour):
        Line(Line(0, 0, 0, 0)), colour(colour)
        {
        }
		RenderLine(Point a, Point b, Colour colour):
        colour(colour)
        {
            this->a = a;
            this->b = b;
        }
		void render();
	};
};