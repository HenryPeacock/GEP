#pragma once
#ifndef RESOURCES_H
#define RESOURCES_H
#include <list>
#include "PeacockEngine/Resource.h"
#include "rend/Context.h"



namespace Peacock
{
	class Core;

	class Resources
	{
	public:
		template <typename T>
		shared<T> Load(std::string _path)
		{

		}
	private:
		friend class Core;

		weak<Core> m_core;
		std::list<shared<Resource>> m_resources;
	};
}

#endif