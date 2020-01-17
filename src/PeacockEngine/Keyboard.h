#pragma once
#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "SDL2/SDL.h"
#include "macros.h"
#include <memory>
#include <vector> 

class Core;

// Add Keyboard Stuff
class Keyboard
{
public:
	void OnTick();

	bool GetKey(SDL_Keycode _keycode);
	bool GetKeyPressed(SDL_Keycode _keycode);
	bool GetKeyReleased(SDL_Keycode _keycode);
private:
	friend class Core;

	std::vector<SDL_Keycode> m_keys;
	std::vector<SDL_Keycode> m_keysPressed;
	std::vector<SDL_Keycode> m_keysReleased;
	weak<Core> m_core;
};

#endif