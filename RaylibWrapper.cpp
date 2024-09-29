#include <raylib.h>

#include "SunsetCore/Rendering/Rendering.hpp"
#include "SunsetCore/Rendering/Sprite.hpp"
#include "SunsetCore/Input.hpp"

//Stuff to ease the rest of rendering.
namespace RaylibWrapperForRendering
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

//Rendering...
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
		RaylibWrapperForRendering::drawPoint(getX(), getY(), colour);
	}
	void RenderLine::render()
	{
		RaylibWrapperForRendering::drawLine(a, b, colour);
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
		DrawFPS(10, 10);
		EndDrawing();
	}

	void* loadTexture(std::string name)
	{
		void* ret = new Texture;
		(*(Texture*)ret) = LoadTexture(name.c_str());
		return ret;
	}

	Sprite::Sprite(std::string name)
	{
		data = loadTexture(name);
	}
	Sprite::~Sprite()
	{
		delete ((Texture*)data);
	}

	void Sprite::render()
	{
		DrawTexture(*(Texture*)data, getX(), getY(), (Color){0, 0, 0, 255});
	}

	void RenderCircle::render()
	{
		DrawCircle(getX(), getY(), radius, RaylibWrapperForRendering::getRaylibColour(colour));
	}
}

/*
	The start of the input wrapper...
*/

namespace RaylibWrapperForInput
{
	int getKeyPressed()
	{
		return GetKeyPressed();
	}
};

namespace SunsetEngine
{
	void Button::update()
	{
		was_button_pressed = (GetCharPressed() == getBinding());
	}
	void Cursor::update()
	{
		left = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
		right = IsMouseButtonPressed(MOUSE_BUTTON_RIGHT);

		position.setXY(GetMousePosition().x, GetMousePosition().y);
	}
};