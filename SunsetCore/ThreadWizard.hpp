/*
	This file will be responsible for containing
	the mythical "Thread Wizard" who will control
	and manage the different threads the engine
	allowing for faster physics handling and
	processing so that applications can do
	MORE in LESS time.

	This will be worked on seperate to the main
	engine and will probably merge at a MUCH
	later date.
*/
#pragma once

#include <vector>
#include <thread>

namespace SunsetEngine
{
	class ThreadWizard
	{
		private:
		std::vector<std::thread*> threads;

		bool finished_with_threads;
		protected:
		public:
		ThreadWizard(){}
		void addThread(std::thread* new_thread){ threads.push_back(new_thread); }
		std::thread* getThread(int index){ return threads.at(index); }
		void synchronise()
		{
			//Just-in-case.
			if(threads.size())
			{
				//Goes through and re-joins all of the loose threads.
				for(auto &current_thread : threads)
				{
					current_thread->join();
					delete current_thread;
					current_thread = nullptr;
				}
				//Clears the queue thread.
				threads.clear();
			}
			// for(int i = 0; i != threads.size(); i++)
			// {
			// 	threads.at(i)->join();
			// }
		}
		bool getFinished(){ return finished_with_threads; }
		~ThreadWizard(){}
	};
};