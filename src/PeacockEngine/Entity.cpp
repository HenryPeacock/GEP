#include "Entity.h"
//#include "Component.h"

namespace Peacock
{
	shared<Core> Entity::getCore()
	{
		return shared<Core>();
	}
	void Entity::display()
	{
		for (std::vector<shared<Component>>::iterator it = components.begin(); it != components.end(); it++)
		{
			(*it)->onDisplay();
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
