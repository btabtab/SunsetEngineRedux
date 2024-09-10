#pragma once

namespace SunsetEngine
{
	class Colour
	{
	private:
		uint8_t r, g, b, a;
	public:
		Colour(int r, int g, int b, int alpha):
		r(r), g(g), b(b), a(alpha)
		{
		}
		uint8_t getRed(){ return r; }
		uint8_t getGreen(){ return g; }
		uint8_t getBlue(){ return b; }
		uint8_t getAlpha(){ return a; }
	};
}