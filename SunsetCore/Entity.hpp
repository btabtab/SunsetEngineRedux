#pragma once

#include "PhysicsObject.hpp"
#include "Rendering/RenderObject.hpp"
#include "MessageLogs.hpp"

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
		std::string name;
	public:
		Entity():
		ID(0), name("BLANK")
		{
		}
		Entity(int ID, RenderObject* render_object):
		ID(ID), render_object(render_object)
		{
		}
		int getID(){ return ID; }
		virtual void behaviour() = 0;
		void render()
		{
			if(render_object == nullptr)
			{
				logMessage("Entity has NULL RenderObject.");
				return;
			}
			render_object->render();
		}
		std::string getName(){ return name; }
		virtual ~Entity()
		{
			delete render_object;
		}
	};
}