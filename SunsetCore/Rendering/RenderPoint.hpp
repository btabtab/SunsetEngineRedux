#pragma once

#include "RenderObject.hpp"
#include "Colour.hpp"
#include "../Point.hpp"

namespace SunsetEngine
{
	//Derives from Point and RenderObject
	class RenderPoint : public Point, public RenderObject
	{
	private:
		Colour colour;
	public:
		RenderPoint(Colour colour);
		RenderPoint(float x, float y, Colour colour);
		RenderPoint(Point point, Colour colour);
		void render();
	};
};