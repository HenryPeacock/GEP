#include "Component.h"
#include "Entity.h"


void Component::OnInitialize()
{
}

void Component::OnTick()
{
}

void Component::OnDisplay()
{

}
shared<Entity> Component::GetEntity()
{
	return m_entity.lock();
}

shared<Core> Component::GetCore()
{
	return GetEntity()->GetCore();
}
