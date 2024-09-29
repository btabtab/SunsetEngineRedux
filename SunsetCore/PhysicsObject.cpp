#include "PhysicsObject.hpp"

namespace SunsetEngine
{
    void PhysicsObject::update()
    {
        if(!is_paused)
        {
            return;
        }
        if(use_gravity)
        {
            direction = direction + Point(0, mass);
        }
        position = position + direction;
    }
	void PhysicsObject::bounce()
    {
        direction.setY(direction.getY() * -bounce_strength);
    }
    
	/*
		Keeping pause explicit and not a
		toggle so that behavious is
		predictable.
	*/
	void PhysicsObject::pause()
    {
        is_paused = true;
    }
	void PhysicsObject::unpause()
    {
        is_paused = false;
    }
};