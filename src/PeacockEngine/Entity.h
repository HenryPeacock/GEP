#pragma once
#ifndef ENTITY_H
#define ENTITY_H


#include <vector>
#include <memory>
#include "macros.h"


class Component;
class Core;

class Entity
{
public:

	template <typename T>
	shared<T> AddComponent()
	{
		shared<T> rtn = makesh<T>();
		rtn->m_entity = m_self;
		rtn->OnInitialize();
		m_components.push_back(rtn);
		return rtn;
	}
	template <typename T, typename A>
	shared<T> AddComponent(A a)
	{
		shared<T> rtn = makesh<T>();
		rtn->m_entity = m_self;
		rtn->OnInitialize(A a);
		m_components.push_back(rtn);
		return rtn;
	}

	shared<Core> GetCore();
	void Display();
	void Tick();

private:
	friend class Core;

	std::vector<shared<Component>> m_components;
	weak<Core> m_core;
	weak<Entity> m_self;
};


#endif

