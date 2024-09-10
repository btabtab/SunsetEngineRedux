#include "Rendering/Rendering.hpp"
#include <raylib.h>

namespace RaylibWrapper
{
	Color getRaylibColour(SunsetEngine::Colour colour)
	{
		return (Color){
						colour.getRed(),
						colour.getGreen(),
						colour.getBlue(),
						colour.getAlpha()
						};
	}
	Vector2 getRaylibVector2(SunsetEngine::Point point)
	{
		return (Vector2){point.getX(), point.getY()};
	}

	void drawPoint(int x, int y, SunsetEngine::Colour colour)
	{
		DrawLine(x - 1, y - 1, x + 1, y + 1, getRaylibColour(colour));
		DrawLine(x - 1, y + 1, x + 1, y - 1, getRaylibColour(colour));
	}
	void drawLine(
					SunsetEngine::Point a,
					SunsetEngine::Point b,
					SunsetEngine::Colour colour
				)
	{
		DrawLine(
				a.getX(), a.getY(),
				b.getX(), b.getY(),
				getRaylibColour(colour)
				);
	}
	void initRaylib()
	{
	}
}

void SunsetEngine::RenderPoint::render()
{
	RaylibWrapper::drawPoint(getX(), getY(), colour);
}