#pragma once

#include "RenderObject.hpp"
#include "../Point.hpp"
#include "Colour.hpp"

namespace SunsetEngine
{
	//Derives from Point and RenderObject
	class RenderPoint : public Point, public RenderObject
	{
	private:
		Colour colour;
	public:
		RenderPoint(Colour colour):
		colour(colour)
		{
		}
		RenderPoint(float x, float y, Colour colour):
		colour(colour)
		{
			setXY(x, y);
		}
		RenderPoint(Point point, Colour colour):
		colour(colour)
		{
			setXY(point.getX(), point.getY());
		}
		void render();
	};
};