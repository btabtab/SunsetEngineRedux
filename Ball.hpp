#pragma once

#include <iostream>

#include "SunsetCore/Entity.hpp"
#include "SunsetCore/Rendering/RenderObject.hpp"
#include "SunsetCore/Rendering/RenderPoint.hpp"
#include "SunsetCore/Rendering/RenderCircle.hpp"
class Ball : public SunsetEngine::Entity
{
private:
	int bounce_count;
public:
	Ball(SunsetEngine::Point new_position, SunsetEngine::Point direction)
	{
		name = "Ball";
		setPosition(new_position);
		setDirection(direction);
		setMass(0.1);
		setGravityUse(true);
		setBounceStrength(1);
		unpause();

		render_object = new SunsetEngine::RenderCircle(position, 6, SunsetEngine::Colour(230, 120, 255, 255));
	}
	void behaviour()
	{
		// std::cout << position.getY() << "\tG: " << use_gravity << "\tM = " << mass << "\n";
		((SunsetEngine::RenderCircle*)render_object)->setXY(position.getX(), position.getY());
		if(450 < position.getY())
		{
			position.setY(449);
			bounce();
		}
		if(position.getY() < 0)
		{
			position.setY(1);
			bounce();
		}
		if(450 < position.getX())
		{
			position.setX(450);
			reflect();
		}
		if(position.getX() < 49)
		{
			position.setX(50);
			reflect();
		}
	}
};