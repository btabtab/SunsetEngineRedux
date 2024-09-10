#pragma once

#include <iostream>
#include <string>

#include "../Point.hpp"
#include "RenderObject.hpp"
#include "RenderPoint.hpp"
#include "RenderLine.hpp"

namespace SunsetEngine
{
	void initialiseRendering(int fps, std::string window_name, Dimensions dimensions);
	void deinitialiseRendering();
	bool isRendererFinished();
	void drawRenderObject(RenderObject* object);
	void clearScreen();
	void beginDrawing();
	void endDrawing();

}