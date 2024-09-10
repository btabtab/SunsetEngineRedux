#include "SunsetEngine.hpp"

//Starts the engine and it's sub-components.
void SunsetEngine::SunsetEngineCore::intialiseEngine()
{
}
//Safely closes the engine down.
void SunsetEngine::SunsetEngineCore::deinitialiseEngine()
{
}
void SunsetEngine::SunsetEngineCore::runRenderingUpdate()
{
}
void SunsetEngine::SunsetEngineCore::renderNextFrame()
{
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
}
void SunsetEngine::SunsetEngineCore::trackNewMemory(void* new_memory)
{
}

//Returns the current fps.
int SunsetEngine::SunsetEngineCore::getFPS()
{
}
//Used to grab engine run-state.
bool SunsetEngine::SunsetEngineCore::keepEngineRunning()
{
}