#pragma once
#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include "AL/al.h"
#include "AL/alc.h"
#include <memory>
#include <list>
#include "macros.h"

class SoundSource;

class SoundManager
{
public:
	~SoundManager();
	void Initialize();
private:
	friend class Core;

	ALCdevice* m_device;
	ALCcontext* m_context;

	weak<Core> m_core;
	std::list<shared<SoundSource>> m_sounds;
};


#endif