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
	Ball(SunsetEngine::Point new_position)
	{
		name = "Ball";
		render_object = new SunsetEngine::RenderLine(
								SunsetEngine::Point(40, 40),
								SunsetEngine::Point(45, 45),
								SunsetEngine::Colour(230, 230, 100, 255));
		setPosition(new_position);
		setDirection(SunsetEngine::Vector(0.5, -20));
		setMass(0.25);
		setGravityUse(true);
		setBounceStrength(0.5);
		unpause();
	}
	void behaviour()
	{
		SunsetEngine::RenderLine* r_obj = (SunsetEngine::RenderLine*)render_object;
		r_obj->setPointA(r_obj->getPointA() = position);
		r_obj->setPointB(r_obj->getPointB() = SunsetEngine::Point(0, 0));
		if(450 < position.getY())
		{
			position.setY(449);
			bounce();
		}
		if(450 < position.getX())
		{
			position.setX(51);
		}
		if(position.getX() < 49)
		{
			position.setX(449);
		}
	}
};