#pragma once
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

	class Entity
	{
	public:

		template <typename T>
		shared<T> addComponent()
		{
			shared<T> rtn = makesh<T>();

			components.push_back(rtn);

			return rtn;
		}

		void display();
		void tick();

	private:
		std::vector<shared<Component>> components;
	};
}

