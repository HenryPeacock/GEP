#pragma once
#ifndef SOUND_H
#define SOUND_H

#include "Resource.h"
#include <AL/al.h>
#include <vector>

/**
 * Class to contain the sound system
 */
class Sound : public Resource
{
public:
	void OnLoad(std::string _path); ///< function to set up sounds system when it is laoded
	void Load_ogg(const std::string & _fileName, std::vector<char>& _buffer, ALenum & _format, ALsizei & _freq); ///< Function which creates the sound
private:
	friend class SoundSource;
	ALuint m_ID;
};


#endif