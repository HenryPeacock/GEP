#include "Core.h"
#include "Resources.h"

namespace Peacock
{

	shared<Core> Core::initialize()
	{
		shared<Core> rtn = makesh<Core>();
		rtn->self = rtn;

		rtn->window = SDL_CreateWindow("PeacockEngine",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			800, 600,
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

		if (!rtn->window)
		{
			throw rend::Exception("Failed to open GUI window");
		}

		SDL_GLContext glContext = SDL_GL_CreateContext(rtn->window);

		if (!glContext)
		{
			throw rend::Exception("Failed to create OpenGL context");
		}

		rtn->m_context = rend::Context::initialize();
		rtn->m_resources = makesh<Resources>();
		rtn->m_resources->m_core = rtn;

		return rtn;
	}

	shared<Entity> Core::addEntity()
	{
		shared<Entity> rtn = makesh<Entity>();

		entities.push_back(rtn);
		rtn->self = rtn;

		return rtn;
	}

	void Core::run()
	{
		while (running)
		{
			// Basically the main game loop
			for (std::vector<shared<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
			{
				(*it)->tick();
			}

			for (std::vector<shared<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
			{
				(*it)->display();
			}

			// Add further stuff
		}
	}

}



