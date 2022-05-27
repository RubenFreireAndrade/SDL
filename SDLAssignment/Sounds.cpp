#include "Sounds.h"
#include <iostream>

Sounds::Sounds()
{
    m_sound = nullptr;
}

bool Sounds::Load(const std::string& filename)
{
    m_sound = Mix_LoadWAV(filename.c_str());

    if (!m_sound)
    {
        std::cout << "Error loading audio" << std::endl;

        return false;
    }
    return true;
}

void Sounds::Unload()
{
    Mix_FreeChunk(m_sound);
}

void Sounds::SetVolume(int volume)
{
    Mix_VolumeChunk(m_sound, volume);
}

void Sounds::Play(int loop)
{
    if (!Mix_PlayChannel(-1, m_sound, loop))
    {
        std::cout << "Error loading sound" << std::endl;
    }
}
