#pragma once
#ifndef SOUND_H
#define SOUND_H

#include "Resource.h"
#include <AL/al.h>
#include <vector>


class Sound : public Resource
{
public:
	void OnLoad(std::string _path);
	void Load_ogg(const std::string & _fileName, std::vector<char>& _buffer, ALenum & _format, ALsizei & _freq);
private:
	friend class SoundSource;
	ALuint m_ID;
};


#endif