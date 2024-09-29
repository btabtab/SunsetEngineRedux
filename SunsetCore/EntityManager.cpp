#include "EntityManager.hpp"

namespace SunsetEngine
{
	EntityManager::EntityManager()
	{
	}
	void EntityManager::sortEntitiesByID()
	{
	}

	Entity* EntityManager::addEntity(Entity* new_entity)
	{
		logMessage("Added entity : " + new_entity->getName());
		entities.push_back(new_entity);
		return entities.back();
	}
	
	Entity* EntityManager::getEntityFromID(int ID)
	{
		sortEntitiesByID();
		//<- Implement fast search here
		return entities.at(0);
	}
	Entity* EntityManager::getEntityFromIndex(int index)
	{
		return entities.at(index);
	}
	int getEntityIndexFromID(int target_ID)
	{
		//<- Implement fast search here
		return 0;
	}
	
	void EntityManager::deleteEntityFromID(int target_entity_ID)
	{
		delete getEntityFromID(target_entity_ID);
	}
	void EntityManager::deleteEntityFromIndex(int target_entity_index)
	{
		delete getEntityFromIndex(target_entity_index);
		entities.erase(entities.begin() + target_entity_index);
	}
	void EntityManager::clearEntities()
	{
		//Delete every entity pointed to.
		for(int i = 0; i != entities.size(); i++)
		{
			delete entities.at(i);
		}
		//Wipe the vector clean.
		entities.clear();
	}

	/*
		Goes through and executes the
		Entity::behaviour()
		and
		PhysicsObject::update()
		functions and then goes through
		and clears any that need clearing.
	*/
	void EntityManager::update()
	{
		for(int i = 0; i != entities.size(); i++)
		{
			Entity* current_entity = entities.at(i);
			current_entity->behaviour();
			current_entity->update();
		}
	}

	/*
	Renders the RenderObjects in each
	entity.
	*/
	void EntityManager::render()
	{
		for(int i = 0; i != entities.size(); i++)
		{
			entities.at(i)->render();
		}
	}
}