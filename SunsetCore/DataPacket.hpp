#pragma once
#include "MessageLogs.hpp"

namespace SunsetEngine
{
	/*
		DataPackets are to be used for storing and
		transmitting data from point A -> B.
	*/
	class DataPacket
	{
	private:
		void* pointer;
		int size;
	public:
		DataPacket(void* pointer, int size):
		pointer(pointer), size(size)
		{
			if(!pointer)
			{
				logMessage("Null pointer in a DataPacket");
			}
		}
		/*
			This constructor is to be used incase there is
			a vector or array being saved to a data packet.
		*/
		DataPacket(void* pointer, int size, int elements):
		pointer(pointer), size(size)
		{
			if(!pointer)
			{
				logMessage("Null pointer in a DataPacket");
			}
		}
	};
}