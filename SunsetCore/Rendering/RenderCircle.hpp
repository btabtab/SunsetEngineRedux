#pragma once

#include "RenderObject.hpp"
#include "../Point.hpp"
#include "Colour.hpp"

namespace SunsetEngine
{
	//Derives from Point and RenderObject
	class RenderCircle : public Point, public RenderObject
	{
	private:
		Colour colour;
    protected:
        float radius;
	public:
		RenderCircle(Colour colour, int new_ID):
		colour(colour)
		{
            radius = 0;
            x = y = 0;
			ID = new_ID;
		}
		RenderCircle(float x, float y, float radius, Colour colour, int new_ID):
		colour(colour), radius(radius)
		{
			setXY(x, y);
			ID = new_ID;
		}
		RenderCircle(Point center, float radius, Colour colour, int new_ID):
		colour(colour), radius(radius)
		{
			setXY(center.getX(), center.getY());
			ID = new_ID;
		}
		void render();
	};
};