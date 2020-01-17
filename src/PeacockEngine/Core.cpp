#include "Core.h"
#include "Keyboard.h"
#include "Resources.h"
#include "Entity.h"
#include "SoundManager.h"
#include "Camera.h"


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

	rtn->m_camera = makesh<Camera>();
	rtn->m_camera->m_core = rtn;

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
	while (m_running)
	{
		//
		m_keyboard->OnTick();
		// Basically the main game loop
		for (std::vector<shared<Entity>>::iterator it = m_entities.begin(); it != m_entities.end(); it++)
		{
			(*it)->Tick();
			// Keyboard
			if (m_keyboard->GetKeyPressed(SDLK_f))
			{
				std::cout << "Successfully Paid Respects" << std::endl;
			}
			if (m_keyboard->GetKeyPressed(SDLK_w))
			{
				m_move -= 1.0f;
			}
			if (m_keyboard->GetKeyPressed(SDLK_s))
			{
				m_move += 1.0f;
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




