#pragma once
#ifndef SOUND_SOURCE_H
#define SOUND_SOURCE_H

#include "Sound.h"
#include "Resource.h"
#include <string>

/**
 * Function containing details about the source of the sound being played
 */
class SoundSource : public Resource
{
public:
	//SoundSource(std::string _path);
	void OnLoad(std::string _path); ///< Function to assign the file to the sound
	void OnTick(); 
	void SetAR(bool _AR) { m_AR = _AR; }
	void SetSound(shared<Sound> _sound) { m_sound = _sound; }
private:
	ALuint m_ID;
	bool m_AR;
	shared<Sound> m_sound; ///< pointer to sound
};


#endif