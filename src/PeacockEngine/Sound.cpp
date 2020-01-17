#include "Sound.h"
#include "stb_vorbis.h"

void Sound::OnLoad(std::string _path)
{
	m_ID = 0;
	alGenBuffers(1, &m_ID);

	ALenum format = 0;
	ALsizei freq = 0;
	std::vector<char> bufferData;
	
	Load_ogg(_path, bufferData, format, freq);

	alBufferData(m_ID, format, &bufferData[0], static_cast<ALsizei>(bufferData.size()), freq);
}

void Sound::Load_ogg(const std::string & _fileName, std::vector<char>& _buffer, ALenum & _format, ALsizei & _freq)
{
  int channels = 0;
  int sampleRate = 0;
  short* output = NULL;

  size_t samples = stb_vorbis_decode_filename(
    _fileName.c_str(), &channels, &sampleRate, &output);

  if (samples == -1)
  {
    throw std::exception();
  }

  _freq = sampleRate;


  if (channels == 1)
  {
    _format = AL_FORMAT_MONO16;
  }
  else
  {
    _format = AL_FORMAT_STEREO16;


    _format = AL_FORMAT_MONO16;
    _freq *= 2;
  }

  _buffer.resize(sizeof(*output) * channels * samples);
  memcpy(&_buffer.at(0), output, _buffer.size());

  // Clean up
  free(output);
}