#include "MainMenuState.h"

bool MainMenuState::OnEnter(Screen& screen)
{
	m_background = std::make_unique<Background>();
	m_background->Initialise(screen);
	m_mainMenu.Initialise(screen);
	return true;
}

MainMenuState::MainMenuState()
{
}

GameState* MainMenuState::Update(Input& input)
{
	m_background->Update(input);
	m_mainMenu.Update(input);
	return this;
}

bool MainMenuState::Render(Screen& screen)
{
	m_background->Render(screen);
	m_mainMenu.Render(screen);
	return true;
}

void MainMenuState::OnExit()
{
	m_mainMenu.ShutDown();
}