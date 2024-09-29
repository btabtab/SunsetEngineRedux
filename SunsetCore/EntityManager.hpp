#pragma once

#include <vector>
#include "Entity.hpp"

namespace SunsetEngine
{
	class EntityManager
	{
	private:
		std::vector<Entity*> entities;
		
		//Sorts the entities by their internal IDs.
		void sortEntitiesByID();

	public:
		EntityManager(/* args */);
		//Adds a new entity and returns it.
		Entity* addEntity(Entity* new_entity);
		//Gets the desired entity from their internal ID.
		Entity* getEntityFromID(int ID);
		//Gets the desired entity from their index.
		Entity* getEntityFromIndex(int index);

		//Deletes an entity via their internal ID.
		void deleteEntityFromID(int target_entity_ID);
		//Deletes an entity via their index in the list.
		void deleteEntityFromIndex(int target_entity_index);
		//Empties the list of entities.
		void clearEntities();
		int getEntityCount();
		
		void updateFirstHalf();
		void updateSecondHalf();

		void update();
		void render();
	};
}