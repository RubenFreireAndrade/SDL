#include <iostream>

#include "Music.h"

bool Music::Initialise() // Maybe pass through? not hard coded.
{
    if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024))
    {
        std::cout << "Error Initilise audio" << std::endl;

        return false;
    }
    return true;
}

Music::Music()
{
    m_music = nullptr;
}

bool Music::Load(const std::string& filename)
{
    m_music = Mix_LoadMUS(filename.c_str());

    if (!m_music)
    {
        std::cout << "Error loading audio" << std::endl;

        return false;
    }
    return true;
}

void Music::Shutdown()
{
    Mix_CloseAudio();
}

void Music::Unload()
{
    Mix_FreeMusic(m_music);
}

void Music::SetVolume(int volume)
{
    Mix_VolumeMusic(volume);
}

void Music::Play()
{
    if (!Mix_PlayingMusic())
    {
        Mix_PlayMusic(m_music, -1); // -1 = Endless Loop and 1 = Play Once.
    }
}

void Music::Pause()
{
    if (!Mix_PausedMusic())
    {
        Mix_PauseMusic();
    }
}

void Music::Resume()
{
    if (!Mix_PausedMusic())
    {
        Mix_ResumeMusic();
    }
}

void Music::Stop()
{
    if (!Mix_PlayingMusic())
    {
        Mix_HaltMusic();
    }
}
