#include "Multiplayer.h"

Multiplayer::Multiplayer()
{
}

Multiplayer::~Multiplayer()
{
}

bool Multiplayer::SDLNetInitialize()
{
	if (SDLNet_Init() == -1)
	{
		std::cout << "SDL_net is not initialize properly" << std::endl;
		return false;
	}
    return true;
}

bool Multiplayer::OpenSocket()
{
	if (SDLNet_ResolveHost(&ip, "localhost", port) == -1)
	{
		std::cout << "Could not connect to server" << std::endl;
		return false;
	}

	listenSocket = SDLNet_TCP_Open(&ip);
	if (!listenSocket)
	{
		std::cout << "Could not find server" << std::endl;
		return false;
	}
	return true;
}

void Multiplayer::ShutDown()
{
	SDLNet_Quit();
}
