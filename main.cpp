#include <vector>

#include "SunsetCore/SunsetEngine.hpp"

#include "Ball.hpp"

int main(int argc, char const *argv[])
{
	SunsetEngine::SunsetEngineCore core(
						SunsetEngine::Dimensions(500, 500),
						std::string(argv[0]),
						60
						);
	// core.getButtonList()->addButton(SunsetEngine::Button("Pause", 'p'));
	core.getEntityManager()->addEntity(new Ball(SunsetEngine::Point(60, 400), SunsetEngine::Vector(40, 30)));
	
	// for(float i = 0; i < 1000; i++)
	// {
	// 	core.getEntityManager()->addEntity(new Ball(SunsetEngine::Point(250, 250), SunsetEngine::Vector(10 + (i / 30), 40 - (i / 30))));
	// }
	core.mainLoop();
	return 0;
}
