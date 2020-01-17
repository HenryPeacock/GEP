#pragma once
#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "SDL2/SDL.h"
#include "macros.h"
#include <memory>
#include <vector> 

class Core;

/**
 * Class containing functions to allow keyboard input
 */
class Keyboard
{
public:
	void OnTick(); ///< Called every tick to update keyboard systems

	bool GetKey(SDL_Keycode _keycode); ///< Gets the keys vector
	bool GetKeyPressed(SDL_Keycode _keycode); ///< Gets the list of keys that have been pressed
	bool GetKeyReleased(SDL_Keycode _keycode); ///< Gets the lsit of keys that have been released
private:
	friend class Core;

	std::vector<SDL_Keycode> m_keys; ///< vector of keys
	std::vector<SDL_Keycode> m_keysPressed; ///< vector of keys that have been pressed
	std::vector<SDL_Keycode> m_keysReleased; ///< vector of keys that have been released
	weak<Core> m_core; ///< pointer to core
};

#endif