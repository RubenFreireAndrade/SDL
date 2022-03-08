#include "Game.h"

Game::Game(GameState* initialState)
{
	m_gameState.reset(initialState);
}

bool Game::Initialize()
{
	//Init screen 
	//Init music system
	//Init Font system
	//Init third-party libraries
	return true;
}

bool Game::Run()
{
	m_gameState->OnEnter();
	while (m_gameState)  //will break if m_gameState == nullptr
	{
		//clearing the screen

		//updating the input

		//checking delta time

		//updating the current game state

		//current game state will return a pointer to a different state if a switch is required 
		//If no switch is required then the current states pointer is returned
		GameState* nextState = m_gameState->Update();

		m_gameState->Render();

		//This will only run if a switch is required
		if (nextState != m_gameState.get())
		{
			m_gameState->OnExit();
			m_gameState.reset(nextState);

			if (m_gameState)
			{
				m_gameState->OnEnter();
			}
		}

		//rendering the screen
	}
	return true;
}

void Game::Shutdown()
{

}
