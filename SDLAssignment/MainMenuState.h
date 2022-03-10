#pragma once
#include "GameState.h"
#include "MainMenu.h"
#include "WriteToScreen.h"
#include "Background.h"
#include <memory>

class MainMenuState : public GameState
{
public:
	MainMenuState();

	// Inherited via GameState
	virtual GameState* Update(Input& input) override;
	virtual bool Render(Screen& screen) override;
	virtual void OnExit() override;
	virtual bool OnEnter(Screen& screen);

private:
	
	MainMenu m_mainMenu;
	std::unique_ptr<Background> m_background;
	WriteToScreen m_writeToScreen;
};

