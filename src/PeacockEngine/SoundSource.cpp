#include "SoundSource.h"

void SoundSource::OnLoad(std::string _path)
{
	m_sound = makesh<Sound>();
	m_sound->OnLoad(_path);

	ALuint sid = 0;
	alGenSources(1, &sid);
	alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
	alSource3f(sid, AL_POSITION, 0.0f, 0.0f, 0.0f);
	alSourcei(sid, AL_BUFFER, m_sound->m_ID);
	alSourcePlay(sid);
}


void SoundSource::OnTick()
{
}
