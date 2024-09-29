#include "SunsetEngine.hpp"

//Starts the engine and it's sub-components.
void SunsetEngine::SunsetEngineCore::intialiseEngine()
{
	initialiseRendering(fps_limit, instance_name, resolution);
}
//Safely closes the engine down.
void SunsetEngine::SunsetEngineCore::deinitialiseEngine()
{
	entity_manager.clearEntities();
	deinitialiseRendering();
}
void SunsetEngine::SunsetEngineCore::runRenderingUpdate()
{
	beginDrawing();
}
void SunsetEngine::SunsetEngineCore::renderNextFrame()
{
	endDrawing();
}

SunsetEngine::SunsetEngineCore::SunsetEngineCore(
									Dimensions resolution,
									std::string instance_name,
									int fps_limit
												)
:resolution(resolution), instance_name(instance_name), fps_limit(fps_limit)
{
	is_engine_still_running = true;
	is_engine_paused = false;
	log_everything = debug_mode = true;

	intialiseEngine();
}
void SunsetEngine::SunsetEngineCore::mainLoop()
{
	/*
		Checks if the engine is still running
		and if all of the threads are done.
	*/
	while((is_engine_still_running || !thread_wizard.getFinished()) && isRendererFinished())
	{
		handEntityUpdatesToThreadWizard();
		thread_wizard.synchronise();
		runRenderingUpdate();
		clearScreen();
		entity_manager.render();
		RenderLine(Point(30, 30), Point(35, 35), Colour(120, 120, 155, 255)).render();
		renderNextFrame();
		
		cursor.update();
		buttons.updateButtons();

		RenderCircle(cursor.getPosition(), 5, Colour(30, 120, 140, 255)).render();
	}
	deinitialiseEngine();
}
void SunsetEngine::SunsetEngineCore::trackNewMemory(void* new_memory)
{
}

//Returns the current fps.
int SunsetEngine::SunsetEngineCore::getFPS()
{
	return 0;
}
//Used to grab engine run-state.
bool SunsetEngine::SunsetEngineCore::keepEngineRunning()
{
	return is_engine_still_running;
}

void SunsetEngine::SunsetEngineCore::queueScript(std::string script_to_run)
{
	script_queue.push_back(script_to_run);
}
void SunsetEngine::SunsetEngineCore::runNextScript()
{
}

void SunsetEngine::SunsetEngineCore::handEntityUpdatesToThreadWizard()
{
	if(128 < entity_manager.getEntityCount())
	{
		// std::cout << "updateFirstHalf()" << "\n";
		thread_wizard.addThread(new std::thread(&EntityManager::updateFirstHalf, entity_manager));
		// std::cout << "updateSecondHalf()" << "\n";
		thread_wizard.addThread(new std::thread(&EntityManager::updateSecondHalf, entity_manager));
		return;
	}
	entity_manager.updateFirstHalf();
	entity_manager.updateSecondHalf();
}
