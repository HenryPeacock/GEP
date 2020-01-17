#pragma once
#ifndef ENTITY_H
#define ENTITY_H


#include <vector>
#include <memory>
#include "macros.h"


class Component;
class Core;

/**
 * An Entity, which is essentially a manager of all it's attached components
 */
class Entity
{
public:

	template <typename T>
	shared<T> AddComponent() ///< Template to add component
	{
		shared<T> rtn = makesh<T>();
		rtn->m_entity = m_self;
		rtn->OnInitialize();
		m_components.push_back(rtn);
		return rtn;
	}
	template <typename T, typename A>
	shared<T> AddComponent(A a) ///< Template to add component with perameters
	{
		shared<T> rtn = makesh<T>();
		rtn->m_entity = m_self;
		rtn->OnInitialize(a);
		m_components.push_back(rtn);
		return rtn;
	}

	shared<Core> GetCore(); ///< Function to get core
	void Display(); ///< Display function
	void Tick(); ///< Function to be called every tick

private:
	friend class Core;

	std::vector<shared<Component>> m_components; ///< Vector containing all components within the Entity
	weak<Core> m_core; ///< Pointer to core
	weak<Entity> m_self; ///< Reference to self
};


#endif

