#include "Point.hpp"

namespace SunsetEngine
{
	class PhysicsObject
	{
	protected:
		//Where the object is.
		Point position;
		//Where the object will go.
		Vector direction;
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
		PhysicsObject(){}
		PhysicsObject(
						Point position,
						Vector direction,
						bool use_gravity = true,
						float mass = 1,
						float bounce_strength = 0.75
					);

		void update();
		void bounce();
		void setDirection(Vector new_direction)	{ direction = new_direction; }
		void setPosition(Point new_position)	{ position = new_position; }
		void setMass(float new_mass)			{ mass = new_mass; }
		void setGravityUse(bool new_use_gravity){ use_gravity = new_use_gravity; }
		void setBounceStrength(float new_bounce_strength){ bounce_strength = new_bounce_strength; }

		void pause();
		void unpause();
	};
}