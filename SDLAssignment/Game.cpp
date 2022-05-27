#include "Game.h"

Game::Game(GameState* initialState)
{
	m_gameState.reset(initialState);
}

bool Game::Initialize()
{
	m_screen.Initialize("SaveData/Config.ini");
	m_music.Initialise();
	m_textToScreen.Initialise();
	return true;
}

bool Game::Run()
{
	m_gameState->OnEnter(m_screen);
	while (m_gameState)
	{
		m_screen.Clear();

		GameState* nextState = m_gameState->Update(m_input);

		m_gameState->Render(m_screen);
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
	m_textToScreen.ShutDown();
	m_music.Shutdown();
	m_screen.Shutdown();
}
