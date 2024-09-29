#pragma once

namespace SunsetEngine
{
	class Point
	{
	private:
	protected:
		float x, y;
	public:
		Point(){}
		Point(float x, float y):
		x(x), y(y)
		{
		}
		//Gets the "x" value.
		float getX(){ return x; }
		//Gets the "y" value.
		float getY(){ return y; }
		//Sets the "x" value.
		void setX(float new_x){ x = new_x; }
		//Sets the "y" value.
		void setY(float new_y){ y = new_y; }
		//Sets the "x" and "y" values.
		void setXY(float new_x, float new_y){ setX(new_x); setY(new_y); }
		//Point operators:
		Point operator+(Point other)
		{
			return Point(x + other.getX(), y + other.getY());
		}
		Point operator-(Point other)
		{
			return Point(x - other.getX(), y - other.getY());
		}
		Point operator*(Point other)
		{
			return Point(x * other.getX(), y * other.getY());
		}
		Point operator/(Point other)
		{
			return Point(x / other.getX(), y / other.getY());
		}
		//Single operators:
		Point operator+(float other)
		{
			return Point(x + other, y + other);
		}
		Point operator-(float other)
		{
			return Point(x - other, y - other);
		}
		Point operator*(float other)
		{
			return Point(x * other, y * other);
		}
		Point operator/(float other)
		{
			return Point(x / other, y / other);
		}
	};
	typedef Point Dimensions;
	typedef Point Vector;
}