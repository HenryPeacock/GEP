#include "Core.h"


namespace Peacock
{

	shared<Core> Core::initialize()
	{
		shared<Core> rtn = makesh<Core>();

		rtn->self = rtn;

		return rtn;
	}

	shared<Entity> Core::addEntity()
	{
		shared<Entity> rtn = makesh<Entity>();

		entities.push_back(rtn);
		rtn->self = rtn;

		return rtn;
	}

	void Core::run()
	{
		while (running)
		{
			// Basically the main game loop
			for (std::vector<shared<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
			{
				(*it)->tick();
			}

			for (std::vector<shared<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
			{
				(*it)->display();
			}

			// Add further stuff
		}
	}

}



