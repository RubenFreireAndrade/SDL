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
#include "WriteToScreen.h"
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

int gameState = 2;
bool isGameRunning = true;
//TODO: Organise this to make into a state for GAMELOOP.
int main(int argc, char* argv[])
{
	std::unique_ptr<Game> game = std::make_unique<Game>(new PlayState);
	if (game->Initialize())
	{
		game->Run();
		game->Shutdown();
	}
	//std::list<GameObject*> objects{};

	////Initialising Classes.
	//Screen screen;
	//Background background;
	//MainMenu mainMenu;
	//EndScreen endScreen;
	//Input input;
	//Sprite sprite;
	//Enemy enemy({ 1100, 470 }, {100, 470});
	//Player player;
	//WriteToScreen text(&player);
	//Music music;
	//Coin coin1/*(750, 140)*/, coin2/*(500, 350)*/;
	//Platform platform/*(400, 400)*/, platform2/*(650, 200)*/;

	//if (!screen.Initialize())
	//{
	//	return 0;
	//}
	//TTF_Init();
	//// For PlayState
	//player.Initialise(screen, &objects);
	//background.Initialise(screen);
	//enemy.Initialise(screen, &objects);
	//coin1.Initialise(screen, &objects);
	//coin2.Initialise(screen, &objects);
	//platform.Initialise(screen, &objects);

	//coin1.SetPosition(750, 140);
	//coin2.SetPosition(500, 350);
	//platform.SetPosition(400, 400);
	//platform2.SetPosition(650, 200);
	//// ============================================
	//
	//// For MainMenu State
	//mainMenu.Initialise(screen);
	//// ============================================
	//
	//// For PlayState.
	//objects.push_back(&background);
	//objects.push_back(&player);
	//objects.push_back(&enemy);
	//objects.push_back(&platform);
	//objects.push_back(&platform2);
	//objects.push_back(&coin1);
	//objects.push_back(&coin2);

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

	return 0;
}