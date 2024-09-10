#pragma once

#include "Point.hpp"

namespace SunsetEngine
{
	class Line
	{
	private:
    protected:
		Point a, b;
	public:
        Line():
        a(0, 0), b(0, 0)
        {
        }
		Line(Point a, Point b):
		a(a), b(b)
		{
		}
        Line(float a_x, float a_y, float b_x, float b_y):
        a(Point(a_x, a_y)), b(b_x, b_y)
        {
        }
        void swapPoints()
        {
            Point swap = a;
            a = b;
            b = swap;
        }

	};
}