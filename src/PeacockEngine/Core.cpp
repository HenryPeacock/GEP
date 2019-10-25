#include "Core.h"

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
		for (size_t i = 0; i < entities.size(); i++)
		{
			entities.at(i)->display();
		}
	}
}


