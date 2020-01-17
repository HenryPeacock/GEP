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
class Camera;

/**
 * The core class is the main framework/ structure of the engine. It provides the setup initialization,
as well as containing the main "game loop"
 */
class Core
{
public:
	shared<Entity> AddEntity(); ///< Add a new entity, called when an entity is created
	void Run(); ///< Function containing the main game loop

	shared<Core> Initialize(); ///< Initial setup of core and therefore engine 
	shared<Resources> GetResources() { return m_resources; }
	void Exit() { m_running = false; } ///< Simple function to exit the program
private:
	friend class MeshRenderer;
	friend class PMesh;
	friend class Material;


	bool m_running = true; ///< running as a bool for the main game loop

	weak<Core> m_self; ///< pointer to self

	SDL_Window* m_window; ///< the window 

	std::vector<shared<Entity>> m_entities; ///< Vector containing all entities
	shared<Resources> m_resources; ///< pointer to resources
	shared<SoundManager> m_soundManager; ///< pointer to sound manager
	shared<Keyboard> m_keyboard; ///< pointer to keyboard
	shared<rend::Context> m_context; ///< pointer to rend context
	shared<Camera> m_camera; ///< pointer to camera
	float m_move = -10.0f;
};


#endif