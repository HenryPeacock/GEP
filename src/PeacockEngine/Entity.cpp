#include "Entity.h"
#include "Component.h"


shared<Core> Entity::GetCore()
{
	return m_core.lock();
}
void Entity::Display()
{
	for (std::vector<shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
	{
		(*it)->OnDisplay();
	}
}
void Entity::Tick()
{
	for (std::vector<shared<Component>>::iterator it = m_components.begin(); it != m_components.end(); it++)
	{
		(*it)->OnTick();
	}
}

