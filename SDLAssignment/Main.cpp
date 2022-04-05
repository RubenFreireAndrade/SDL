#include <iostream>
#include <list>
#include <memory>

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Sprite.h"
#include "Input.h"
#include "Screen.h"
#include "Player.h"
#include "Enemy.h"
#include "TextToScreen.h"
#include "Vector2D.h"
#include "Coin.h"
#include "GameObject.h"
#include "Music.h"
#include "Bullet.h"
#include "Background.h"
#include "Enemy.h"
#include "Platform.h"
#include "MainMenu.h"
#include "EndScreen.h"
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

	////Initialising Classes.
	//TextToScreen text(&player);
	//Music music;

	//if (!screen.Initialize())
	//{
	//	return 0;
	//}
	//TTF_Init();
	//// For PlayState

	
	//// ============================================
	//
	//// For MainMenu State
	//mainMenu.Initialise(screen);
	//// ============================================
	//
	//// For PlayState.

	//music.Initialise();
	//music.SetVolume(0);
	//music.Load("Assets/Audio/NarutoIntro.mp3");
	//music.Play();
	//// ============================================

	//while (isGameRunning)
	//{
	//	input.Update();
	//	screen.Clear();
	//	auto it = std::begin(objects);

	//	switch (gameState)
	//	{

	//	case 1: // MAIN SCREEN.

	//		mainMenu.Render(screen);
	//		mainMenu.Update(input);

	//		if (input.IsKeyPressed())
	//		{
	//			gameState = 2;
	//		}
	//		break;

	//	case 2: // GAME LOOP

	//		while (it != std::end(objects))
	//		{
	//			text.RenderScore(screen);

	//			if ((*it)->IsFlaggedForDeletion())
	//			{
	//				it = objects.erase(it);
	//			}
	//			else
	//			{
	//				(*it)->CheckCollision(objects);
	//				(*it)->PreUpdate(input);
	//				(*it)->Render(screen);
	//				++it;
	//			}
	//		}
	//		if (player.GetScore() >= 4)
	//		{
	//			endScreen.RenderEndScreen(screen, 0);
	//		}
	//		else if (player.IsFlaggedForDeletion())
	//		{
	//			endScreen.RenderEndScreen(screen, 1);
	//		}
	//		break;

	//	default:

	//		break;
	//	}
	//	// Cleaning screen buffer.
	//	SDL_SetRenderDrawColor(screen.GetRenderer(), 0, 0, 0, 255);
	//	SDL_RenderPresent(screen.GetRenderer());

	//	if (input.IsWindowClosed())
	//	{
	//		isGameRunning = false;
	//	}

	//	if (input.IsKeyDown(SDLK_ESCAPE))
	//	{
	//		isGameRunning = false;
	//	}
	//}
	//SDL_Quit();
	//TTF_Quit();
	//sprite.Unload();
	//screen.Shutdown();
}