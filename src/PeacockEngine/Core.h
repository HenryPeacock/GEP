#pragma once
#ifndef CORE_H
#define CORE_H

#include <vector>
#include "macros.h"
#include <SDL2/SDL.h>
#include "rend/rend.h"


class MeshRenderer;
class Entity;
class PMesh;
class SoundManager;
class Resources;
class Keyboard;

class Core
{
public:
	shared<Entity> AddEntity();
	void Run();

	shared<Core> Initialize(); 
	shared<Resources> GetResources() { return m_resources; }
private:
	friend class MeshRenderer;
	friend class PMesh;
	friend class Material;


	bool m_running = true;
	weak<Core> m_self;

	SDL_Window* m_window;

	std::vector<shared<Entity>> m_entities;
	shared<Resources> m_resources;
	shared<SoundManager> m_soundManager;
	shared<Keyboard> m_keyboard;
	shared<rend::Context> m_context;
};


#endif