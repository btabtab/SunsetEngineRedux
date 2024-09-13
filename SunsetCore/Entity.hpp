#pragma once

#include "PhysicsObject.hpp"
#include "Rendering/RenderObject.hpp"

namespace SunsetEngine
{
	class Entity : public PhysicsObject
	{
	private:
		/* data */
		int ID;
	protected:
		//The affiliated RenderObject.
		RenderObject* render_object;
	public:
		Entity():
		ID(0)
		{
		}
		Entity(int ID, RenderObject* render_object):
		ID(ID), render_object(render_object)
		{
		}
		int getID(){ return ID; }
		virtual void behaviour() = 0;
		void render(){ render_object->render(); }
		virtual ~Entity()
		{
			delete render_object;
		}
	};
}