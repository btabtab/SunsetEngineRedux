#include "SunsetEngine.hpp"

//Starts the engine and it's sub-components.
void SunsetEngine::SunsetEngineCore::intialiseEngine()
{
	initialiseRendering(fps_limit, instance_name, resolution);
}
//Safely closes the engine down.
void SunsetEngine::SunsetEngineCore::deinitialiseEngine()
{
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

	are_threads_all_caught_up = false;

	intialiseEngine();
}
void SunsetEngine::SunsetEngineCore::mainLoop()
{
	/*
		Checks if the engine is still running
		and if all of the threads are done.
	*/
	while((is_engine_still_running || !are_threads_all_caught_up) && isRendererFinished())
	{
		handleThreads();

		entity_manager.update();
		runRenderingUpdate();
		clearScreen();
		entity_manager.render();
		RenderLine(Point(30, 30), Point(35, 35), Colour(120, 120, 155, 255)).render();
		renderNextFrame();
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

void SunsetEngine::SunsetEngineCore::runNewThread(std::thread* thread_to_add)
{
	threads_queue.push_back(thread_to_add);
}
void SunsetEngine::SunsetEngineCore::handleThreads()
{
	//Just-in-case.
	if(threads_queue.size())
	{
		//Goes through and re-joins all of the loose threads.
		for(auto &current_thread : threads_queue)
		{
			current_thread->join();
			current_thread = nullptr;
		}
		//Clears the queue thread.
		threads_queue.clear();
	}
}
void SunsetEngine::SunsetEngineCore::queueScript(std::string script_to_run)
{
	script_queue.push_back(script_to_run);
}
void SunsetEngine::SunsetEngineCore::runNextScript()
{
	runNewThread(new std::thread(system, script_queue.back().c_str()));
	std::cout << "Running: " << script_queue.back().c_str() << "\n";
	script_queue.pop_back();
}