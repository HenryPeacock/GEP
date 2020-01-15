#pragma once
#ifndef CORE_H
#define CORE_H

#include "Entity.h"
#include "macros.h"
#include "rend/rend.h"

#include <memory>
#include <iostream>
#include <list>


class SoundManager;

namespace Peacock
{
	class Resources;

	class Core
	{
	public:
		shared<Entity> addEntity();
		void run();

		static shared<Core> initialize(); 

	private:
		friend class MeshRenderer;
		friend class PMesh;


		bool running = true;
		weak<Core> self;

		SDL_Window* window;

		std::vector<shared<Entity>> entities;
		shared<Resources> m_resources;
		shared<SoundManager> m_soundManager;
		shared<rend::Context> m_context;
	};
}

#endif