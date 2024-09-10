#pragma once

namespace SunsetEngine
{
	class Colour
	{
	private:
		int r, g, b, a;
	public:
		Colour(int r, int g, int b, int alpha):
		r(r), g(g), b(b), a(a)
		{
		}
		int getRed(){ return r; }
		int getGreen(){ return g; }
		int getBlue(){ return b; }
		int getAlpha(){ return a; }
	};
}