#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include "GL/glew.h"
#include "Component.h"
#include <glm/glm.hpp>
#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "macros.h"

namespace Peacock
{
	//class Component;
	class Core;

	class Entity
	{
		friend class Core;
	public:

		template <typename T>
		shared<T> addComponent()
		{
			shared<T> rtn = makesh<T>();
			components.push_back(rtn);
			rtn->onInitialize();
			return rtn;
		}
		template <typename T, typename A>
		shared<T> addComponent(A a)
		{
			shared<T> rtn = makesh<T>();
			components.push_back(rtn);
			rtn->onInitialize(A a);
			return rtn;
		}

		shared<Core> getCore();
		void display();
		void tick();

	private:
		std::vector<shared<Component>> components;
		weak<Core> core;
		weak<Entity> self;
	};
}

#endif

