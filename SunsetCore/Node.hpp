#pragma once
#include "MessageLogs.hpp"
namespace SunsetEngine
{
	class Node
	{
	private:
		Node* child = nullptr;
		Node* parent = nullptr;
		void* contents = nullptr;

		void failsafeCheckContents()
		{
			if(!contents)
			{
				SunsetEngine::logMessage("Node contents found NULL");
			}
		}

	public:
		Node(Node* child, void* contents):
		child(child), parent(nullptr), contents(contents)
		{
		}
		Node(Node* child, Node* parent, void* contents):
		child(child), parent(parent), contents(contents)
		{
		}
		Node* getNextNode()
		{
			return child;
		}
		Node* getParentNode()
		{
			return parent;
		}
	};
};