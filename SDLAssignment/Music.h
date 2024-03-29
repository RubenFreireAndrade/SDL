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
	void SetVolume(int volume);
	void Unload();
	void Shutdown();
	
	void Play();
	void Pause();
	void Resume();
	void Stop();

private:

	Mix_Music* m_music;

};

