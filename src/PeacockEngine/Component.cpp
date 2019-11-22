#include "Component.h"
#include "Entity.h"

namespace Peacock
{
	void Peacock::Component::onInitialize()
	{
	}

	void Peacock::Component::onTick()
	{
	}

	void Component::onDisplay()
	{

	}
	shared<Entity> Component::getEntity()
	{
		return entity.lock();
	}
}