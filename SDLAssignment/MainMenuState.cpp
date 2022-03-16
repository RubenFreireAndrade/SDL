#include "MainMenuState.h"

MainMenuState::MainMenuState()
{
}

bool MainMenuState::OnEnter(Screen& screen)
{
	m_background = std::make_unique<Background>();
	m_mainMenu = std::make_unique<MainMenu>();
	m_background->Initialise(screen);
	m_mainMenu->Initialise(screen);
	return true;
}

GameState* MainMenuState::Update(Input& input)
{
	input.Update();
	m_background->Update(input);
	m_mainMenu->Update(input);

	if (input.IsKeyPressed())
	{
		return new PlayState;
	}
	return this;
}

bool MainMenuState::Render(Screen& screen)
{
	m_background->Render(screen);
	m_mainMenu->Render(screen);
	return true;
}

void MainMenuState::OnExit()
{
	m_mainMenu->ShutDown();
}