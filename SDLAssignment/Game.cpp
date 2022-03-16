#include "Game.h"

Game::Game(GameState* initialState)
{
	m_gameState.reset(initialState);
}

bool Game::Initialize()
{
	//Init music system
	//Init Font system
	//Init third-party libraries
	m_screen.Initialize("SDL_Platformer");
	m_music.Initialise();

	return true;
}

bool Game::Run()
{
	m_gameState->OnEnter(m_screen);
	while (m_gameState)  //will break if m_gameState == nullptr
	{
		//clearing the screen
		m_screen.Clear();
		//updating the input

		//checking delta time

		//updating the current game state
		GameState* nextState = m_gameState->Update(m_input);

		m_gameState->Render(m_screen);
		//This will only run if a switch is required
		if (nextState != m_gameState.get())
		{
			m_gameState->OnExit();
			m_gameState.reset(nextState);
			if (m_gameState)
			{
				m_gameState->OnEnter(m_screen);
			}
		}
		m_screen.Present();
	}
	return true;
}

void Game::Shutdown()
{
	m_music.Shutdown();
	m_screen.Shutdown();
}
