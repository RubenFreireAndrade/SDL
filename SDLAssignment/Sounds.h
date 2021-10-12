#pragma once

#include <string>
#include <SDL_mixer.h>

class Sounds
{

public:

	Sounds();

	bool Load(const std::string& filename);
	void Unload();

	void SetVolume(int volume);

	void Play(int loop);

private:

	Mix_Chunk* m_sound;
};

