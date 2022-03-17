#pragma once
#include "GameState.h"
#include "MainMenu.h"
#include "TextToScreen.h"
#include "Background.h"
#include "PlayState.h"
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
	std::unique_ptr<MainMenu> m_mainMenu;
	//MainMenu m_mainMenu;
	PlayState m_playState;
	std::unique_ptr<Background> m_background;
	TextToScreen m_textToScreen;
};

