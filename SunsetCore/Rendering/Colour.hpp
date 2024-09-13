#pragma once

typedef unsigned char byte;

namespace SunsetEngine
{
	class Colour
	{
	private:
		byte r, g, b, a;
	public:
		Colour():
		r(0), g(0), b(0), a(0)
		{
		}
		Colour(byte r, byte g, byte b, byte alpha):
		r(r), g(g), b(b), a(alpha)
		{
		}
		byte getRed(){ return r; }
		byte getGreen(){ return g; }
		byte getBlue(){ return b; }
		byte getAlpha(){ return a; }
	};
}