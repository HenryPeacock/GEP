#pragma once
#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include "AL/al.h"
#include "AL/alc.h"
#include <memory>
#include <list>
#include "macros.h"

class SoundSource;

/**
 * Class to manage the different sounds
 */
class SoundManager
{
public:
	~SoundManager(); ///< deconstructor
	void Initialize(); ///< Function to set up the manager
private:
	friend class Core;

	ALCdevice* m_device; ///< Sound device
	ALCcontext* m_context; ///< Sound context

	weak<Core> m_core; ///< Pointer to core
	std::list<shared<SoundSource>> m_sounds; ///< List of sounds within the program
};


#endif