#pragma once
#include <iostream>

namespace SunsetEngine
{
	void logMessage(std::string message)
	{
		static int message_count = 0;
		std::cout << "[ " << message_count++ << " ]::>{ " \
		<< message << " }\n";
	}
};