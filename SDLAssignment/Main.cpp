#include <iostream>
#include <list>
#include <thread>
#include <memory>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "MainMenuState.h"
#include "Game.h"
#include "PlayState.h"

int main(int argc, char* argv[])
{
	std::unique_ptr<Game> game = std::make_unique<Game>(new MainMenuState);
	if (game->Initialize())
	{
		game->Run();
		game->Shutdown();
	}
	return 0;
}