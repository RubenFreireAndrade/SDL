#pragma once

#include <SDL_mixer.h>

#include <string>

class Music
{

public:

	enum class LoopAudio {};
	static bool Initialise();
	Music();

	bool Load(const std::string& filename);

	void Shutdown();

	void Unload();

	void SetVolume(int volume);
	
	void Play();
	void Pause();
	void Resume();
	void Stop();

private:

	Mix_Music* m_music;

};

