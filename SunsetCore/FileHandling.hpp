#pragma once
#include <iostream>

#include "DataPacket.hpp"

namespace SunsetEngine
{
	class FileHandler
	{
	private:
	public:
		void saveFile(std::string file_name, DataPacket data_packet);
	};

};