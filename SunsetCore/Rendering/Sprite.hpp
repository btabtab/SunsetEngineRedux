#pragma once

#include <string>
#include "../Point.hpp"
#include "RenderObject.hpp"

namespace SunsetEngine
{
	class Sprite : public Point, public RenderObject
	{
	protected:
		void* data;
	public:
		Sprite(std::string file_name);
		void render();
		~Sprite();
	};
};