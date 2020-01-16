#pragma once
#ifndef RESOURCES_H
#define RESOURCES_H
#include <list>
#include "PeacockEngine/Resource.h"
#include "rend/Context.h"




class Core;

class Resources
{
public:
	template <typename T>
	shared<T> Load(std::string _path)
	{
		for (std::list<shared<Resource>>::iterator it = m_resources.begin();
			it != m_resources.end(); it++)
		{
			if ((*it)->GetPath() == _path)
			{
				return std::dynamic_pointer_cast<T>(*it);
			}
		}
		shared<T> rtn = makesh<T>();
		rtn->m_core = m_core;
		rtn->OnLoad(_path);
		m_resources.push_back(rtn);

		return rtn;
	}
private:
	friend class Core;

	weak<Core> m_core;
	std::list<shared<Resource>> m_resources;
};

#endif