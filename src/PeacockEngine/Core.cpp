#include "Core.h"
#include "Keyboard.h"
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

	rtn->m_soundManager = makesh<SoundManager>();
	rtn->m_soundManager->Initialize();
	rtn->m_soundManager->m_core = rtn;

	rtn->m_keyboard = makesh<Keyboard>();
	rtn->m_keyboard->m_core = rtn;

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
	m_running = true;
	SDL_Event e = { 0 };

	while (m_running)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				m_running = false;
			}
		}

		// Basically the main game loop
		for (std::vector<shared<Entity>>::iterator it = m_entities.begin(); it != m_entities.end(); it++)
		{
			(*it)->Tick();
			// Keyboard
			if (m_keyboard->GetKey(SDLK_f))
			{
				std::cout << "Hola" << std::endl;
			}
		}

		glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (std::vector<shared<Entity>>::iterator it = m_entities.begin(); it != m_entities.end(); it++)
		{
			(*it)->Display();
		}

		// Add further stuff
		SDL_GL_SwapWindow(m_window);
	}
}




