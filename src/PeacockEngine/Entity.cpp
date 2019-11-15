#include "Entity.h"

namespace Peacock
{
	void Entity::display()
	{
		for (size_t i = 0; i < components.size(); i++)
		{
			components.at(i)->onDisplay();
		}
	}
	void Entity::tick()
	{
		for (std::vector<shared<Component>>::iterator it = components.begin(); it != components.end(); it++)
		{
			(*it)->onTick();
		}
	}
}
