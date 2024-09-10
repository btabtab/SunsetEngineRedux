#include <vector>

#include "SunsetCore/SunsetEngine.hpp"

int main(int argc, char const *argv[])
{
	SunsetEngine::SunsetEngineCore core(
						SunsetEngine::Dimensions(500, 500),
						"SunsetEngine test.",
						60
						);
	core.mainLoop();
	return 0;
}
