#include "SoundManager.h"

SoundManager::~SoundManager()
{
	alcMakeContextCurrent(NULL);
	alcDestroyContext(m_context);
}

void SoundManager::Initialize()
{
	m_device = alcOpenDevice(NULL);
	if (!m_device)
	{
		throw std::exception();
	}

	m_context = alcCreateContext(m_device, NULL);
	if (!m_context)
	{
		alcCloseDevice(m_device);
		throw std::exception();
	}
	if (!alcMakeContextCurrent(m_context))
	{
		alcDestroyContext(m_context);
		alcCloseDevice(m_device);
		throw std::exception();
	}
}
