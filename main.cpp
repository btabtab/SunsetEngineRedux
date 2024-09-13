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
	core.getButtonList()->addButton(SunsetEngine::Button("Pause", 'p'));
	core.getEntityManager()->addEntity(new Ball());
	core.mainLoop();
	return 0;
}
