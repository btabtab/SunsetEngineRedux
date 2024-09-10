#include <raylib.h>

#include "SunsetCore/Rendering/Rendering.hpp"

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
}

namespace SunsetEngine
{
	void initialiseRendering(int fps, std::string window_name, Dimensions dimensions)
	{
		InitWindow(dimensions.getX(), dimensions.getY(), window_name.c_str());
		SetTargetFPS(fps);
	}
	void deinitialiseRendering()
	{
		endDrawing();
		CloseWindow();
	}
	bool isRendererFinished()
	{
		return ( !WindowShouldClose() );
	}
	void RenderPoint::render()
	{
		RaylibWrapper::drawPoint(getX(), getY(), colour);
	}
	void RenderLine::render()
	{
		RaylibWrapper::drawLine(a, b, colour);
	}
	void clearScreen()
	{
		ClearBackground(BLACK);
	}
	void beginDrawing()
	{
		BeginDrawing();
	}
	void endDrawing()
	{
		EndDrawing();
	}
}