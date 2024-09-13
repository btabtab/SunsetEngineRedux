#pragma once

#include <iostream>

#include "SunsetCore/Entity.hpp"
#include "SunsetCore/Rendering/RenderObject.hpp"
#include "SunsetCore/Rendering/RenderPoint.hpp"
class Ball : public SunsetEngine::Entity
{
private:
	int bounce_count;
public:
	Ball()
	{
		name = "Ball";
		render_object = new SunsetEngine::RenderLine(
								SunsetEngine::Point(40, 40),
								SunsetEngine::Point(45, 45),
								SunsetEngine::Colour(230, 230, 100, 255));
		setMass(10);
		setGravityUse(true);
		setBounceStrength(0.5);
	}
	void behaviour(){ std::cout << "I am a ball\n"; }
};