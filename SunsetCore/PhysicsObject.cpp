#pragma once

#include "Point.hpp"

namespace SunsetEngine
{
	class PhysicsObject
	{
	private:
		//Where the object is.
		Point position;
		//Where the object will go.
		Point direction;
		/*
			Controls if the object is
			affected by gravity.
		*/
		bool use_gravity;
		//How heavy the object is.
		float mass;
		//Value between 0.01 and 1.00.
		float bounce_strength;

		bool is_paused;
	public:
		PhysicsObject(
						Point position,
						Point direction,
						bool use_gravity = true,
						float mass = 1,
						float bounce_strength = 0.75
					);
	};
}