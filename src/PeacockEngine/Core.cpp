#include "Core.h"


namespace Peacock
{

	shared<Core> Core::initialize()
	{
		shared<Core> c = makesh<Core>();
		return c;
	}

	shared<Entity> Core::addEntity()
	{
		shared<Entity> rtn = makesh<Entity>();

		entities.push_back(rtn);

		return rtn;
	}

	void Core::run()
	{
		while (true)
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



