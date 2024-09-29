#pragma once

#include <string>
#include <vector>

#include <thread>

#include "MessageLogs.hpp"
#include "Node.hpp"
#include "Point.hpp"
#include "FileHandling.hpp"
#include "EntityManager.hpp"
#include "Input.hpp"
#include "ThreadWizard.hpp"

#include "Rendering/Rendering.hpp"

namespace SunsetEngine
{
	class SunsetEngineCore
	{
	private:

		//The highest FPS that the engine will go.
		int fps_limit;
		//The name of the instance.
		std::string instance_name;
		//This will track all of the allocated memory.
		std::vector<DataPacket> allocated_memory;
		//The size of the main window.
		Dimensions resolution;
		//This will control if the engine is still going.
		bool is_engine_still_running;
		//This willl track if the engine is paused or not.
		bool is_engine_paused;
		//This tracks debug state.
		bool debug_mode;
		//Should EVERYTHING be logged.
		bool log_everything;

		ThreadWizard thread_wizard;

		//Starts the engine and it's sub-components.
		void intialiseEngine();
		//Safely closes the engine down.
		void deinitialiseEngine();

		void runRenderingUpdate();
		void renderNextFrame();
		std::vector<std::string> script_queue;

		EntityManager entity_manager;

		Cursor cursor;
		ButtonList buttons;

		void handEntityUpdatesToThreadWizard();

	public:

		SunsetEngineCore(Dimensions resolution, std::string instance_name, int fps_limit);
		void mainLoop();
		void trackNewMemory(void* new_memory);
		
		//Returns the current fps.
		int getFPS();
		//Used to grab engine run-state.
		bool keepEngineRunning();

		/*
			This will queue a script for running. This
			is so that I can throw the scripts into
			a bunch of parallel threads meaning that
			I can run them without impacting the
			program's performance.
		*/
		void queueScript(std::string script_to_run);
		/*
			This is a very niche tool for the engine.
			The only real use is for any API's that need
			working with which might be some depending
			on the use of the engine for whatever project.
		*/
		void runNextScript();

		EntityManager* getEntityManager(){ return &entity_manager; }

		ButtonList* getButtonList(){ return &buttons; }
	};
};