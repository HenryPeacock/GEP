#include "Core.h"

#include "Resources.h"
#include "Entity.h"
#include "SoundManager.h"


shared<Core> Core::Initialize()
{
	shared<Core> rtn = makesh<Core>();
	rtn->m_self = rtn;

	rtn->m_window = SDL_CreateWindow("PeacockEngine",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		800, 600,
		SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	if (!rtn->m_window)
	{
		throw rend::Exception("Failed to open GUI window");
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(rtn->m_window);

	if (!glContext)
	{
		throw rend::Exception("Failed to create OpenGL context");
	}

	rtn->m_context = rend::Context::initialize();
	rtn->m_resources = makesh<Resources>();
	rtn->m_resources->m_core = rtn;

	return rtn;
}

shared<Entity> Core::AddEntity()
{
	shared<Entity> rtn = makesh<Entity>();
	rtn->m_self = rtn;
	rtn->m_core = m_self;
	m_entities.push_back(rtn);


	return rtn;
}

void Core::Run()
{
	while (m_running)
	{
		// Basically the main game loop
		for (std::vector<shared<Entity>>::iterator it = m_entities.begin(); it != m_entities.end(); it++)
		{
			(*it)->Tick();
		}

		for (std::vector<shared<Entity>>::iterator it = m_entities.begin(); it != m_entities.end(); it++)
		{
			(*it)->Display();
		}

		// Add further stuff
	}
}



